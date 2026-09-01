/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<TreeNode*> solve(int st, int end, map<pair<int, int>, vector<TreeNode*>>& mp){
        if(st > end){
            return {nullptr};
        }

        if(mp.count({st, end})){
            return mp[{st, end}];
        }

        vector<TreeNode*> result;
        for(int i=st; i<=end; i++){
            vector<TreeNode*> leftBST = solve(st, i-1, mp);
            vector<TreeNode*> rightBST = solve(i+1, end, mp);

            for(auto& l : leftBST){
                for(auto& r : rightBST){
                    TreeNode* root = new TreeNode(i);
                    root -> left = l;
                    root -> right = r;
                    result.push_back(root);
                }
            }
        }

        return mp[{st, end}] = result;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> mp;
        return solve(1, n, mp);
    }
};