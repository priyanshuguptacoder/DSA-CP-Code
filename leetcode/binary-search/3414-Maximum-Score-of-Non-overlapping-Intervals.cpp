class Solution {
public:
    int n;
    struct Node {
        long long score = -1;
        vector<int> idx;
    };

    vector<int> nextIdx;
    vector<vector<Node>> dp;
    int findNext(vector<vector<int>>& a, int r) {
        int lo = 0, hi = n - 1;
        int ans = n;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (a[mid][0] > r) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return ans;
    }

    Node solve(vector<vector<int>>& a, int i, int k) {
        if (i >= n || k == 0)
            return {0, {}};

        if (dp[i][k].score != -1)
            return dp[i][k];

        Node skip = solve(a, i + 1, k);
        Node take = solve(a, nextIdx[i], k - 1);
        take.score += a[i][2];
        take.idx.push_back(a[i][3]);

        sort(take.idx.begin(), take.idx.end());
        if (skip.score > take.score)
            return dp[i][k] = skip;

        if (skip.score < take.score)
            return dp[i][k] = take;

        return dp[i][k] = (skip.idx < take.idx ? skip : take);
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        for (int i = 0; i < n; i++)
            intervals[i].push_back(i);

        sort(intervals.begin(), intervals.end());
        nextIdx.resize(n);

        for (int i = 0; i < n; i++)
            nextIdx[i] = findNext(intervals, intervals[i][1]);
        dp.assign(n + 1, vector<Node>(5));

        return solve(intervals, 0, 4).idx;
    }
};