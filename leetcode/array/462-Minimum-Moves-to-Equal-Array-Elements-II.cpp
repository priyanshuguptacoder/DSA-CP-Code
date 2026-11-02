class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int median = nums[n/2];

        long long ans = 0;
        for(int x : nums){
            ans += abs(x - median);
        }

        return ans;
    }
};