class Solution {
public:
    int numberOfSets(int n, int k) {
        int MOD = 1e9 + 7;
        vector<vector<long long>>dp (1001, vector<long long> (1001, 0));
        for(int i=0; i<=n-1; i++){
            dp[0][i] = 1;
        }

        for(int i=1; i<=k; i++){
            vector<long long> prevRowSum(n+1, 0);
            for(int j=n-1; j>=0; j--){
                prevRowSum[j] = (prevRowSum[j+1] + dp[i-1][j]) % MOD;
            }

            for(int j=n-1; j>=0; j--){
                long long take = prevRowSum[j+1];
                long long skip = dp[i][j+1] % MOD;
                dp[i][j] = (take + skip) % MOD;
            }
        }
        return dp[k][0];
    }
};