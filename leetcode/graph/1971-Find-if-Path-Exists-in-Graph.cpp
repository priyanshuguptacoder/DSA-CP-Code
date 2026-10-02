class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n+1, false);
        queue<int> q;
        vector<vector<int>> adj(n);

        q.push(source);
        visited[source] = true;

        if(source == destination){
            return true;
        }

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        while(!q.empty()){
            int node = q.front();
            int size = q.size();
            q.pop();
            
            for(int nei : adj[node]){
                if(!visited[nei]){
                    q.push(nei);
                    visited[nei] = true;

                    if(nei == destination){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};