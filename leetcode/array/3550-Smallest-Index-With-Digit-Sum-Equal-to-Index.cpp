class Solution {
private:
    int getDigitSum(int n){
        int sum = 0;

        while(n > 0){
            int dig = n % 10;
            sum += dig;
            n /= 10;
        }

        return sum;
    }

public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(getDigitSum(nums[i]) == i){
                return i;
            }
        }
        return -1;
    }
};