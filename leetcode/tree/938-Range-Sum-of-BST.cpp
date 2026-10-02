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
    void sum(TreeNode* root, int low, int high, int& rangeSum){
        if(!root){
            return ;
        }

        if(root -> val >= low && root -> val <= high){
            rangeSum += root -> val;
        }

        sum(root -> left, low, high, rangeSum);
        sum(root -> right, low, high, rangeSum);
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int rangeSum = 0;
        sum(root, low, high, rangeSum);
        
        return rangeSum;
    }
};