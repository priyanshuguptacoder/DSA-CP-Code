class Solution {
public:
    int time;
    vector<int> dt, low;

    void dfs(int u, int parU, vector<bool>& vis, vector<vector<int>>& adj, vector<vector<int>>& cc){
        vis[u] = true;
        dt[u] = low[u] = ++time;

        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(!vis[v]){
                dfs(v, u, vis, adj, cc);

                low[u] = min(low[u], low[v]); //Update low
                if(low[v] > dt[u]){
                    cc.push_back({v, u});
                }
            }
            else if(v != parU){
                low[u] = min(low[u], dt[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        time = 0;
        dt.resize(n, -1);
        low.resize(n);

        vector<vector<int>> bridges;
        for(int i=0; i<n; i++){
            if(dt[i] == -1){
                dfs(i, -1, vis, adj, bridges);
            }
        }

        return bridges;
    }
};