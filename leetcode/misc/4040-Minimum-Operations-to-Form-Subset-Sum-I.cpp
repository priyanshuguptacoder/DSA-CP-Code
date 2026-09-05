class Solution {
    int n, sum;
    vector<vector<int>> dp;
    vector<vector<pair<int, int>>> options;

private:
    void getOptions(vector<int>& nums) {
        options.resize(n);

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            options[i].push_back({x, 0}); // Do nothing

            int val = x; // Multilpy
            int cost = 0;

            while (val > 0 && val <= sum / 2) {
                val *= 2;
                cost++;
                options[i].push_back({val, cost});
            }

            val = x; // Only divide
            cost = 0;
            while (val > 0) {
                val /= 2;
                cost++;

                if (val > 0 && val <= sum) {
                    options[i].push_back({val, cost});
                }
            }
        }
    }

    int solve(vector<int>& nums, int i, int target) {
        if (target == 0) {
            return 0;
        }
        if (i == n || target < 0) {
            return 1e9;
        }

        if (dp[i][target] != -1) {
            return dp[i][target];
        }

        int notTake = solve(nums, i + 1, target); // Don't take nums[i]

        int ans = notTake;
        for (auto [val, cost] : options[i]) { // Use nums[i] after transformng it
            if (val <= target) {
                int next = solve(nums, i + 1, target - val);
                if (next != 1e9) {
                    ans = min(ans, cost + next);
                }
            }
        }

        return dp[i][target] = ans;
    }

public:
    int minOperations(vector<int>& nums, int sum) {
        n = nums.size();
        this->sum = sum;

        dp.assign(n, vector<int>(sum + 1, -1));
        getOptions(nums);
        int ans = solve(nums, 0, sum);

        return ans == 1e9 ? -1 : ans;
    }
};