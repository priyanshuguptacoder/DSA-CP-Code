class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), sum = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            mp[sum] = i;
        }

        if(sum < x) return -1;

        int rest = sum - x, cur = 0, longest = -1;

        for(int i = 0; i < n; i++) {
            cur += nums[i];
            if(mp.count(cur - rest))
                longest = max(longest, i - mp[cur - rest]);
        }

        return longest == -1 ? -1 : n - longest;
    }
};