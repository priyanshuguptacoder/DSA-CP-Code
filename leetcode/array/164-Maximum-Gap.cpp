class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if(n <= 1){
            return 0;
        }

        int maxDiff = 0;
        for(int i=0; i<n-1; i++){
            maxDiff = max(maxDiff, (nums[i+1] - nums[i]));
        }
        
        return maxDiff;
    }
};