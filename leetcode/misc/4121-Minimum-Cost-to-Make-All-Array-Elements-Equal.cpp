class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MAX;

        for(int i=0; i<n; ){
            int j = i;

            while(j + 1 < n && nums[j+1] == nums[i]){ //Find the maximum continguous block of same value
                j++;
            }

            if(i <= n - 2 && j >= 1){ //Check whether this block contain atleast one valid internal index
                long long len = j - i + 1;
                long long cost = 1LL * nums[i] * (n - len);
                ans = min(ans, cost);
            }

            i = j + 1;
        }

        return ans;
    }
};