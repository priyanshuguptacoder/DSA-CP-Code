class Solution {
    int checkInc(vector<int>& nums){
        int n = nums.size(), cnt = 0;
        int idx0 = -1;

        for(int i=0; i<n; i++){
            if(nums[i] > nums[(i + 1) % n]){
                cnt++;
            }
            if(nums[i] == 0){
                idx0 = i;
            }
        }

        if(cnt <= 1){
            return min(idx0, n - idx0 + 2);
        }
        
        return 1e9;
    }
    
    int checkDec(vector<int>& nums){
        int n = nums.size(), cnt = 0;
        int idx0 = -1;

        for(int i=0; i<n; i++){
            if(nums[i] < nums[(i + 1) % n]){
                cnt++;
            }
            if(nums[i] == 0){
                idx0 = i;
            }
        }

        if(cnt == 1){
            return min(idx0 + 2, n - idx0);
        }
        
        return 1e9;
    }
    
public:
    int minOperations(vector<int>& nums) {
        vector<int> dranofelik = nums;
        int n = nums.size();

        int op = min(checkInc(nums), checkDec(nums));
        
        return op == 1e9 ? -1 : op;
    }
};