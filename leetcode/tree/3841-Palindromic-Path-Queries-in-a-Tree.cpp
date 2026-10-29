
class Solution {
    class SegmentTree {
        int n;
        vector<int> lazy;

        void update(int node, int l, int r,
                    int ql, int qr, int val) {
            if (qr < l || r < ql)
                return;

            if (ql <= l && r <= qr) {
                lazy[node] ^= val;
                return;
            }

            int mid = l + (r - l) / 2;

            update(node * 2, l, mid, ql, qr, val);
            update(node * 2 + 1, mid + 1, r, ql, qr, val);
        }

        int query(int node, int l, int r, int idx) {
            if (l == r)
                return lazy[node];

            int mid = l + (r - l) / 2;

            int res = lazy[node];

            if (idx <= mid)
                return res ^ query(node * 2, l, mid, idx);

            return res ^ query(node * 2 + 1, mid + 1, r, idx);
        }

    public:
        SegmentTree(int size) {
            n = size;
            lazy.assign(4 * n + 5, 0);
        }

        void rangeXor(int l, int r, int val) {
            if (val == 0) return;
            update(1, 0, n - 1, l, r, val);
        }

        int pointQuery(int idx) {
            return query(1, 0, n - 1, idx);
        }
    };

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries){
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> parent(n, -1);
        vector<int> depth(n, 0);
        vector<int> tin(n), tout(n), order;

        parent[0] = 0;

        stack<pair<int, bool>> st;
        st.push({0, false});

        int timer = 0;
        while (!st.empty()) {
            auto [u, exit] = st.top();
            st.pop();

            if (exit) {
                tout[u] = timer - 1;
                continue;
            }

            tin[u] = timer++;
            order.push_back(u);

            st.push({u, true});

            for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                int v = adj[u][i];
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;

                st.push({v, false});
            }
        }
        
        int LOG = 1;

        while ((1 << LOG) <= n)
            LOG++;
        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            up[0][i] = parent[i];
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v])
                swap(u, v);

            int diff = depth[u] - depth[v];

            for (int k = 0; k < LOG; k++) {
                if (diff & (1 << k))
                    u = up[k][u];
            }

            if (u == v)
                return u;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }
            return parent[u];
        };
        
        vector<int> pref(n, 0);

        for (int u : order) {
            int mask = 1 << (s[u] - 'a');
            if (u == 0)
                pref[u] = mask;
            else
                pref[u] = pref[parent[u]] ^ mask;
        }

        SegmentTree seg(n);
        auto getPrefix = [&](int u) {
            return pref[u] ^ seg.pointQuery(tin[u]);
        };

        vector<bool> ans;

        for (string &q : queries) {
            stringstream ss(q);

            string type;
            int u, v;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;
                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');

                int delta = oldMask ^ newMask;
                seg.rangeXor(tin[u], tout[u], delta);

                s[u] = c;
            } 
            else {
                ss >> v;
                int w = lca(u, v);

                int mask = getPrefix(u) ^ getPrefix(v);
                mask ^= (1 << (s[w] - 'a'));
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
