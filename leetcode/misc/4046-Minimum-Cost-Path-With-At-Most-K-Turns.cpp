class Solution {
private:
    int solve(int i, int j, int turn, int dir, int m, int n, int k, vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>& dp){
        if(turn > k){
            return 1e9;
        }

        if(i == m - 1 && j == n - 1){
            return grid[i][j];
        }

        if(dp[i][j][turn][dir] != -1){
            return dp[i][j][turn][dir];
        }

        int ans = 1e9;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int d=0; d<4; d++){
            int ni = i + dr[d];
            int nj = j + dc[d];

            if(ni < 0 || ni >= m || nj < 0 || nj >= n){
                continue;
            }

            int newTurn = turn + (dir != 4 && dir != d);
            ans = min(ans, solve(ni, nj, newTurn, d, m, n, k, grid, dp));
        }

        return dp[i][j][turn][dir] = grid[i][j] + ans;
    }
    
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<vector<int>>>> dp(m, vector<vector<vector<int>>> (n, vector<vector<int>> (k+1, vector<int> (5, -1)))); //0 = Up, 1 = Right, 2 = Down, 3 = Left, 4 = No previous direction

        int ans = solve(0, 0, 0, 4, m, n, k, grid, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};