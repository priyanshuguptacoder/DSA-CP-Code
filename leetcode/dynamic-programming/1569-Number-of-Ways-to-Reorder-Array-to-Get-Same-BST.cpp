class Solution {
    long long MOD = 1e9 + 7;
    vector<vector<long long>> PT;
    
private:
    int solve(vector<int>& nums){
        int n = nums.size();
        if(n < 3){
            return 1;
        }

        vector<int> left, right;
        int root = nums[0];

        for(int i=1; i<n; i++){
            if(nums[i] < root){
                left.push_back(nums[i]);
            }
            else{
                right.push_back(nums[i]);
            }
        }

        long long l = solve(left);
        long long r = solve(right);

        return ((l * r) % MOD * PT[n-1][left.size()]) % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        PT.resize(n+1);

        for(int i=0; i<=n; i++){
            PT[i] = vector<long long> (i+1, 1);

            for(int j=1; j<i; j++){ //First and last in pascal triangle is 1
                PT[i][j] = (PT[i-1][j] + PT[i-1][j-1]) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD; //-1 becuase ek toh phele se diya hia usse nahi lena hai
    }
};