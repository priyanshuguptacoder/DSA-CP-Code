class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto& e : edges){
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
        }

        vector<vector<int>> dist(n, vector<int> (k+1, INT_MAX)); //reaching the same node with different consecutive character count
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();

            int d = curr[0];
            int node = curr[1];
            int count = curr[2];

            if(d > dist[node][count]){
                continue;
            }

            if(node == n - 1){
                return d;
            }

            for(auto& it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;

                int newCount = (labels[adjNode] == labels[node]) ? count + 1 : 1;
                if(newCount > k){
                    continue;
                }

                int newDist = d + wt;
                if(newDist < dist[adjNode][newCount]){
                    dist[adjNode][newCount] = newDist;
                    pq.push({newDist, adjNode, newCount});
                }
            }
        }

        return -1;
    }
};