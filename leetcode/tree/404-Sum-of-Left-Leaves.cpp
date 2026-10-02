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
    void leafSum(TreeNode* root, int& sum, bool leftTake){
        if(!root){
            return ;
        }
        
        if(!root -> left && !root -> right){ //Leaf Node
            if(leftTake){
                sum += root -> val;
            }
            return ;
        }

        leafSum(root -> left, sum, 1);
        leafSum(root -> right, sum, 0);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        bool leftTake = 1;

        if(!root || (!root -> left && !root -> right)){
            return 0;
        }

        leafSum(root, sum, leftTake);

        return sum;
    }
};