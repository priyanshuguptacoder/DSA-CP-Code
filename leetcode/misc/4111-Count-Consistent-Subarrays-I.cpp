class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int cnt = n;

        for(int i=0; i<n; i++){
            int andi = nums[i];
            for(int j=i+1; j<n; j++){
                andi &= nums[j];
                
                int mini = *min_element(nums.begin()+i, nums.begin()+j+1);
                if(andi == mini){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};