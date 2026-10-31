class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<long long>>> dp(m, vector<vector<long long>> (n, vector<long long> (2, 0))); //Third state is that is comes from right or down for right -> 0, and for down -> 1
        dp[0][1][0] = 1; //First move starting from cell
        dp[1][0][1] = 1;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                for(int d=0; d<2; d++){
                    long long ways = dp[i][j][d];

                    if(ways == 0){
                        continue;
                    }
                    if(grid[i][j] == 1){
                        if(d == 0 && i + 1 < m){ //Mirror: Right -> Down
                            dp[i+1][j][1] = (dp[i+1][j][1] + ways) % MOD;
                        }
                        else if(d == 1 && j + 1 < n){ //Mirror: Down -> Right
                            dp[i][j+1][0] = (dp[i][j+1][0] + ways) % MOD;
                        }
                    }

                    else{
                        if(j + 1 < n){ //Right
                            dp[i][j+1][0] = (dp[i][j+1][0] + ways) % MOD;
                        }
                        if(i + 1 < m){ //Down
                            dp[i+1][j][1] = (dp[i+1][j][1] + ways) % MOD;
                        }
                    }
                }
            }
        }

        return (dp[m-1][n-1][0] + dp[m-1][n-1][1]) % MOD;
    }
};