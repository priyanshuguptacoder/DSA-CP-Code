class Solution {
public:
    vector<string> assignUmbrella(vector<int>& arr) {
        int n = arr.size();

        vector<string> ans(n);
        int alice = 0, bob = 0;
        for(int i=0; i<n; i++){
            if(i < n - 1 && arr[i] == 1 && arr[i+1] == 1){
                if(alice > bob){
                    ans[i] = "Bob";
                    bob++;
                }
                else if(alice <= bob){
                    ans[i] = "Alice";
                    alice++;
                }
            }
            else if(arr[i] == 1){
                ans[i] = "Bob";
                bob++;
            }
            else{
                ans[i] = "None";
            }
        }
        
        return ans;
    }
};