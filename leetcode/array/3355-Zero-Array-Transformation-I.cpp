class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> diff(n+1, 0);
        for(int i=0; i<queries.size(); i++){
            int st = queries[i][0];
            int end = queries[i][1];

            diff[st]++;
            diff[end + 1]--;
        }

        int cnt = 0;
        for(int i=0; i<n; i++){
            cnt += diff[i];

            if(nums[i] > cnt){
                return false;
            }
        }

        return true;
    }
};