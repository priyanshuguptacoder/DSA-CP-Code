class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for(auto& e : times){ //u -> v with weight w
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //Max Heap
        pq.push({0, k});

        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node]){ //Ignore outdated entry
                continue;
            }

            for(auto [next, wt] : adj[node]){
                if(d + wt < dist[next]){
                    dist[next] = d + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        int ans = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == 1e9){
                return -1;
            }

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};