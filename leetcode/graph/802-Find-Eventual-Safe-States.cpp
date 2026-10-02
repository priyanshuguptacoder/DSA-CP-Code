class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> adjRev(n);
        vector<int> indegree(n, 0); //kitne node uspe end ho rahe hai so isme uska graph ko ulta kar denge toh indegree 0 hona chahiye safe node

        for(int i=0; i<n; i++){ //Reverse graph + indegree find -> This is Khan's Algorithm
            for(auto it : graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++){ //Nodes with indegree 0
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> safeNodes;
        while(!q.empty()){ //BFS
            int node = q.front();
            q.pop();

            safeNodes.push_back(node);

            for(auto it : adjRev[node]){
                indegree[it]--; //All outgoing paths from safe nodes lead to safe nodes because we use reverse logic because in questions says safe nodes is that leads to terminal node or ends at safe nodes
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};