class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> result(k, 0);
        vector<long long> prevCnt(k, 0);

        for(int i=0; i<n; i++){ //Single element subarrays
            vector<long long> currCnt(k, 0); //Index i par end hone wale all subarrays
            int currRem = nums[i] % k;
            currCnt[currRem]++;

            for(int old=0; old<k; old++){ //Extend all previous subarrays by nums[i]
                int newRem = (1LL * old * nums[i] % k);
                currCnt[newRem] += prevCnt[old];
            }

            prevCnt = move(currCnt); //Current become previous for next index
            for(int x=0; x<k; x++){
                result[x] += prevCnt[x];
            }
        }

        return result;
    }
};