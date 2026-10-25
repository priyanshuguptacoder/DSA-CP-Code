class Solution {
private:
    int rearrange(int n){
        string s = to_string(n);
        sort(s.rbegin(), s.rend());
        int num = stoi(s);
        return num;
    }

public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        vector<long long> gains;

        for(int x : nums){
            gains.push_back(rearrange(x) - x);
        }

        sort(gains.rbegin(), gains.rend());
        for(int i=0; i<min(k, (int)gains.size()); i++){
            sum += gains[i];
        }
        
        return sum;
    }
};