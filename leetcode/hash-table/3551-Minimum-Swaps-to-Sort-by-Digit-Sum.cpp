class Solution {
private:
    int digSum(int num){
        int sum = 0;

        while(num != 0){
            int dig = num % 10;
            sum += dig;
            num /= 10;
        }
        
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> afterSort(nums);

        sort(afterSort.begin(), afterSort.end(), [&](int a, int b) {
            if(digSum(a) != digSum(b)){
                return digSum(a) < digSum(b);
            }

            return a < b;
        });

        unordered_map<int, int> mp; //num, idx -> before sorting
        for(int i=0; i<n; i++){
            mp[nums[i]] = i;
        }

        int swapCnt = 0;
        for(int i=0; i<n; i++){
            int expVal = afterSort[i];
            int currVal = nums[i];

            if(expVal == currVal){
                continue;
            }

            int idx = mp[expVal];
            swap(nums[i], nums[idx]);

            mp[expVal] = i;
            mp[currVal] = idx;
            swapCnt++;
        }

        return swapCnt++;
    }
};