/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        
        if(root -> val == p-> val || root -> val == q-> val){
            return root;
        }

        TreeNode* leftLCA = lowestCommonAncestor(root -> left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root -> right, p, q);

        if(leftLCA && rightLCA){ //If left and right are both not NULL then that root is LCA
            return root;
        }
        else if(leftLCA != NULL){ //If we are fuiding the LCA and if left is not NULL and right is NULL then the left is LCA
            return leftLCA;
        }
        else{ //LeftLCA is null or both left and right is NULL
            return rightLCA;
        }
    }
};