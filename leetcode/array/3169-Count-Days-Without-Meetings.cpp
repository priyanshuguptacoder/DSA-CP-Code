class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());

        int cnt = 0, last = 0;
        for(int i=0; i<n; i++){
            if(meetings[i][0] > last + 1){
                cnt += meetings[i][0] - last - 1;
            }

            last = max(last, meetings[i][1]);
        }

        cnt += max(0, days - last);

        return cnt;
    }
};