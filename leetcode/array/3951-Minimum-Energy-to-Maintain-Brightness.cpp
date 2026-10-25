class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        long long time = 0;
        long long st = intervals[0][0], end = intervals[0][1];
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][0] <= end){
                end = max(end, (long long)intervals[i][1]);
            }
            else{
                time += end - st + 1;
                st = intervals[i][0];
                end = intervals[i][1];
            }
        }

        time += end - st + 1;
        long long bulb = (brightness + 2) / 3; //Beacuse every bulb covers 3
        return time * bulb;
    }
};