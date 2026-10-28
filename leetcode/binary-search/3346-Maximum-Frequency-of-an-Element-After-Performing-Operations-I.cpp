class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        int low = mini - k;
        int high = maxi + k;
        int n = high - low + 2;

        vector<int> diff(n, 0);
        vector<int> freq(n, 0);

        for(int x : nums){
            freq[x - low]++;

            diff[x - k - low]++;
            diff[x + k + 1 - low]--;
        }

        int active = 0;
        int ans = 0;
        for(int i=0; i<=high-low; i++){
            active += diff[i];

            int possible = min(active, freq[i] + numOperations);
            ans = max(ans, possible);
        }

        return ans;
    }
};