class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<int> resultSize;
    vector<int> last;

    void dfs(int currNode, string& s, vector<int>& parent){
        int c = s[currNode] - 'a';
        int nearestAnc = last[c];

        last[c] = currNode;
        for(int child : adj[currNode]){
            dfs(child, s, parent);
        }

        last[c] = nearestAnc; //Backtracking
        if(currNode != 0){
            int newParent = parent[currNode];

            if(nearestAnc != -1){
                newParent = nearestAnc;
            }
            parent[currNode] = newParent;

            resultSize[newParent] += resultSize[currNode]; //Updated modified subtree size
        }
    }

public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        adj.clear();

        for(int i=1; i<n; i++){
            int u = parent[i];
            int v = i;

            adj[u].push_back(v);
        }

        resultSize.assign(n, 1); //Sab khud ke 1 subtree ka size hai
        last.assign(26, -1);
        
        dfs(0, s, parent);
        return resultSize;
    }
};