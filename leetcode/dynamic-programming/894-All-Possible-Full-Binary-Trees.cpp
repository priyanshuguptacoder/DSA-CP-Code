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
    vector<TreeNode*> solve(int n, unordered_map<int, vector<TreeNode*>>& mp){
        if(n % 2 == 0){ //When even then FBT is not possible
            return {};
        }

        if(n == 1){
            TreeNode* root = new TreeNode(0);
            return {root};
        }

        if(mp.count(n)){
            return mp[n];
        }

        vector<TreeNode*> result;
        for(int i=1; i<n; i+=2){ //Even me FBT nahi ban pa raha hai
            vector<TreeNode*> leftFBT = solve(i, mp);
            vector<TreeNode*> rightFBT = solve(n-i-1, mp);

            for(auto& l : leftFBT){ //Combine every leftBST with rightBST
                for(auto& r : rightFBT){
                    TreeNode* root = new TreeNode(0);
                    root -> left = l;
                    root -> right = r;
                    
                    result.push_back(root);
                }
            }
        }

        return mp[n] = result;
    }

public:
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int, vector<TreeNode*>> mp;
        return solve(n, mp);
    }
};