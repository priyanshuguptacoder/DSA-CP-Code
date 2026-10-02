class Solution {
    int n;
    queue<pair<int, int>> q;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

private:
    void dfs(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || y < 0 || x >= n || y >= n || grid[x][y] != 1){
            return ;
        }

        grid[x][y] = 2; //Mark first island
        q.push({x, y});
        
        for(int i=0; i<4; i++){
            dfs(grid, x + dx[i], y + dy[i]);
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();

        bool found = false; //Step 1 : Find first island
        for(int i=0; i<n && !found; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                    found = true;
                    break;
                }
            }
        }

        int dist = 0; //Step 2 : BFS
        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto [x, y] = q.front();
                q.pop();

                for(int i=0; i<4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx < 0 || ny < 0 || nx >= n || ny >= n){
                        continue;
                    }

                    if(grid[nx][ny] == 1){ //Reached second island
                        return dist;
                    }

                    if(grid[nx][ny] == 0){
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
            dist++;
        }

        return -1;
    }
};