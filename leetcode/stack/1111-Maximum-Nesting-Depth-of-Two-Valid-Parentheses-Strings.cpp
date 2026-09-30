class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        int depth = 0;
        vector<int> ans(n); //We want to string A and B so even depth we can do at even and odd

        for(int i=0; i<n; i++){
            if(seq[i] == '('){
                depth++;
                ans[i] = depth % 2;
            }
            else{
                ans[i] = depth % 2;
                depth--; //If we subtract it first then depth % 2 then it point to depth - 1 which will be wrong
            }
        }

        return ans;
    }
};