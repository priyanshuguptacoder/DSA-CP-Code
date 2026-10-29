class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int time = curr[0];
            int x = curr[1];
            int y = curr[2];

            if(time > dist[x][y]){
                continue;
            }

            if(x == n - 1 && y == m - 1){
                return time;
            }

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                    continue;
                }

                int newTime = max(time, moveTime[nx][ny]) + 1;
                if(newTime < dist[nx][ny]){
                    dist[nx][ny] = newTime;
                    pq.push({newTime, nx, ny});
                }
            }
        }

        return -1;
    }
};