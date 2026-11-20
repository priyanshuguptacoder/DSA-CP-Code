class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        int ans = 0;

        for(int x : nums){
            dp[x+1] = max(dp[x+1], dp[x] + 1); //Increase x to x + 1
            dp[x] = max(dp[x], dp[x-1] + 1); //Keep x unchanged

            ans = max({ans, dp[x+1], dp[x]});
        }

        return ans;
    }
};