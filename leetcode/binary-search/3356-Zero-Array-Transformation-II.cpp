class Solution {
private:
    bool check(vector<int>& nums, vector<vector<int>>& queries, int k){
        int n = nums.size();

        vector<int> diff(n+1, 0);
        for(int i=0; i<k; i++){ //Apply the first k queries using a difference array
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            diff[l] += val;
            diff[r+1] -= val;        
        }

        long long curr = 0;
        for(int i=0; i<n; i++){
            curr += diff[i];

            if(curr < nums[i]){ //Available decrement is insufficient
                return false;
            }
        }

        return true;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size();
        if(!check(nums, queries, q)){
            return -1;
        }

        int low = 0, high = q;
        while(low < high){
            int mid = low + (high - low) / 2;

            if(check(nums, queries, mid)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};