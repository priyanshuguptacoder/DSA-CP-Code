class Solution {
private:
    int calcGCD(vector<int>& arr, int n){
        if(n <= 1){
            return 0;
        }

        vector<int> pref(n);
        vector<int> suff(n);
        
        pref[0] = arr[0]; //Prefix GCD
        for(int i=1; i<n; i++){
            pref[i] = gcd(pref[i-1], arr[i]);
        }

        suff[n-1] = arr[n-1]; //Suffix GCD
        for(int i=n-2; i>=0; i--){
            suff[i] = gcd(arr[i], suff[i+1]);
        }

        int cnt = 0; //Count valid splits
        for(int i=0; i<n-1; i++){
            if(pref[i] == suff[i+1]){
                cnt++;
            }
        }

        return cnt;
    }

public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int del=-1; del<n; del++){ //When del == -1 then wwe aare not deleting anything
            vector<int> arr;
            
            for(int i=0; i<n; i++){
                if(i != del){
                    arr.push_back(nums[i]);
                }
            }

            ans = max(ans, calcGCD(arr, arr.size()));
        }
        
        return ans;
    }
};