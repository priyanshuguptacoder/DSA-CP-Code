class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int cnt = 0;
        int dx[]= {-1, 1, 0, 0};
        int dy[]= {0, 0, -1, 1};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] > 0 && !vis[i][j]){
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = true;
                    
                    long long sum = 0;
                    while(!q.empty()){
                        auto [x, y] = q.front();
                        q.pop();

                        sum += grid[x][y];
                        
                        for(int d=0; d<4; d++){
                            int nx = x + dx[d];
                            int ny = y + dy[d];

                            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] > 0 && !vis[nx][ny]){
                                vis[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }

                    if(sum % k == 0){
                        cnt++;
                    }
                }
            }
        }
        
        return cnt;
    }
};