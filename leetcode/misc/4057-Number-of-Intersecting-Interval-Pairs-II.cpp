class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> start(n), end(n);
        for(int i=0; i<n; i++){
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        long long nonInt = 0;
        int j = 0;

        for(int st : start){
            while(j < n && end[j] < st){ //All intervals whose end is before the start are non Intersecting
                j++;
            }

            nonInt += j;
        }

        long long totalPair = 1LL * n * (n - 1) / 2;
        return totalPair - nonInt; //This is count of intersecting
    }
};