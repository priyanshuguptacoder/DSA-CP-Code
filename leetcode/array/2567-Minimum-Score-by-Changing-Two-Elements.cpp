class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int maxi = nums[n-1] - nums[2]; //Change the two smallest value
        int mini = nums[n-3] - nums[0]; //Change the two largest value
        int middle = nums[n-2] - nums[1]; //Change the smallest and largest

        return min({mini, maxi, middle});
    }
};