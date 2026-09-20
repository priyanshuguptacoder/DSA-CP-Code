class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();

        long long ans = 1e18;
        long long totalSum = 0;
        long long evenSum = 0;
        long long oddSum = -1e18;

        for(int i=0; i<n; i++){
            totalSum += (i % 2 == 0 ? nums[i] : -nums[i]); //Alternating prefix sum

            if((i + 1) % 2 == 0){ //When length is even
                ans = min(totalSum - evenSum, ans);
                evenSum = max(evenSum, totalSum);
            }
            else{ //When length is odd
                ans = min(totalSum - oddSum, ans);
                oddSum = max(oddSum, totalSum);
            }
        }
        
        totalSum -= (2 * min(0LL, ans)); //Apply the best possible improvement
        return totalSum;
    }
};