class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int num : nums){
            mp[num]++;
        }

        int ans = 0;

        int l = 0;
        for(int r=1; r<n; r++){
            if(nums[r] != nums[l]){
                int len = r - l;
                if(mp[nums[l]] == len){
                    ans++;
                }
                l = r;
            }
        }

        if(n - l == mp[nums[n-1]]){
            ans++;
        }

        return ans;
    }
};