/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;

        mp[node] = new Node(node -> val); //Clone first node
        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            for(Node* nei : curr -> neighbors){
                if(!mp.count(nei)){ //Not clone yet
                    mp[nei] = new Node(nei -> val);
                    q.push(nei);
                }

                mp[curr] -> neighbors.push_back(mp[nei]); //Connect clone
            }
        }

        return mp[node];
    }
};