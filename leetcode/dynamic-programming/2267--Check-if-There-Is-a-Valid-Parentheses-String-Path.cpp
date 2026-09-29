class Solution {
private:
    bool solve(int i, int j, int cnt, vector<vector<char>>& grid, vector<vector<vector<int>>>& dp, int m, int n){
        cnt += (grid[i][j] == '(') ? 1 : -1;
        if(cnt < 0){
            return false;
        }

        if(dp[i][j][cnt] != -1){
            return dp[i][j][cnt];
        }

        if(i == m-1 && j == n-1){
            return dp[i][j][cnt] = (cnt == 0);
        }

        if(i + 1 < m){ //Move Down
            if(solve(i+1, j, cnt, grid, dp, m, n)){
                return dp[i][j][cnt] = true;
            }
        }

        if(j + 1 < n){ //Move Right
            if(solve(i, j+1, cnt, grid, dp, m, n)){
                return dp[i][j][cnt] = true;
            }
        }

        return dp[i][j][cnt] = false;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int len = m + n - 1;

        if(len % 2 == 1){
            return false;
        }
        if(grid[0][0] == ')' || grid[m-1][n-1] == '('){
            return false;
        }

        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (len+1, -1)));
        return solve(0, 0, 0, grid, dp, m, n);
    }
};