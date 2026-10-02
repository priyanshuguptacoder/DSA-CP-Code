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
    unordered_map<int, int> mp;

private:
    TreeNode* solve(vector<int>& postOrder, int& postIdx, int left, int right){
        if(left > right){
            return NULL;
        }

        int rootVal = postOrder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        int idx = mp[rootVal]; //Find root position in inorder
        root -> right = solve(postOrder, postIdx, idx + 1, right); 
        root -> left = solve(postOrder, postIdx, left, idx - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx = postorder.size() - 1;

        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return solve(postorder, postIdx, 0, inorder.size() - 1);
    }
};