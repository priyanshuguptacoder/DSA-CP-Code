class Solution {
private:
    void dfs(int i, int j, int n, int m, vector<vector<bool>>& vis, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 1 || vis[i][j]){
            return ;
        }

        vis[i][j] = true;
        dfs(i-1, j, n, m, vis, grid);
        dfs(i, j-1, n, m, vis, grid);
        dfs(i+1, j, n, m, vis, grid);
        dfs(i, j+1, n, m, vis, grid);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        vector<vector<bool>> vis(n, vector<bool> (m, false));

        for(int i=0; i<n; i++){ //Remove all lands connected to boundary
            dfs(i, 0, n, m, vis, grid);
            dfs(i, m-1, n, m, vis, grid);
        }

        for(int i=0; i<m; i++){ //Remove all lands connected to boundary
            dfs(0, i, n, m, vis, grid);
            dfs(n-1, i, n, m, vis, grid);
        }

        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(grid[i][j] == 0 && !vis[i][j]){
                    dfs(i, j, n, m, vis, grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};