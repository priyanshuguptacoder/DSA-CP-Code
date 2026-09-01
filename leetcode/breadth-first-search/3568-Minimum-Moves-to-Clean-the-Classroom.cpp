class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sx = 0, sy = 0;
        int litterCnt = 0;

        vector<vector<int>> id(m, vector<int> (n, -1));  //Give every litter cell an ID
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(classroom[i][j] == 'S'){
                    sx = i;
                    sy = j;
                }
                if(classroom[i][j] == 'L'){
                    id[i][j] = litterCnt++;
                }
            }
        }

        if(litterCnt == 0){
            return 0;
        }

        int totalMask = 1 << litterCnt;
        vector<vector<vector<vector<bool>>>> vis(m, vector<vector<vector<bool>>>(n, vector<vector<bool>>(energy+1, vector<bool>(totalMask, false)))); //visited[row][col][reamining energy][litter that is still not collected]

        queue<tuple<int, int, int, int>> q;
        int initialMask = (1 << litterCnt) - 1; //Initially all litter is uncollected

        q.push({sx, sy, energy, initialMask});
        vis[sx][sy][energy][initialMask] = true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int moves = 0;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto[x, y, currEnergy, mask] = q.front();
                q.pop();

                if(mask == 0){
                    return moves;
                }

                if(currEnergy == 0){
                    continue;
                }

                for(int dir=0; dir<4; dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if(nx < 0 || ny < 0 || nx >= m || ny >= n){
                        continue;
                    }
                    if(classroom[nx][ny] == 'X'){ //Obstacle
                        continue;
                    }

                    int nextEnergy;
                    int nextMask = mask;
                    nextEnergy = currEnergy - 1; //Moving normally consumnes 1 unit energy

                    if(classroom[nx][ny] == 'R'){
                        nextEnergy = energy;
                    }

                    if(classroom[nx][ny] == 'L'){
                        int bit = id[nx][ny];
                        nextMask &= ~(1 << bit); //Mark as that bit 0 another remains 1
                    }

                    if(vis[nx][ny][nextEnergy][nextMask]){
                        continue;
                    }
                    
                    vis[nx][ny][nextEnergy][nextMask] = true;
                    q.push({nx, ny, nextEnergy, nextMask});
                }
            }
            moves++;
        }

        return -1;
    }
};