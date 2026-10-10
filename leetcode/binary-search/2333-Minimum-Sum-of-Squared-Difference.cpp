class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);
        long long sum = 0;
        int maxi = 0;

        int k = k1 + k2;
        for(int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
            maxi = max(maxi, diff[i]);
        }

        if (sum <= k) return 0;

        int low = 0, high = maxi;
        while (low < high) {
            int mid = low + (high - low) / 2;

            long long need = 0;
            for (int x : diff) {
                need += max(0, x - mid);
            }

            if (need <= k){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }

        for(int i = 0; i < n; i++) {
            k -= max(0, diff[i] - low);
            diff[i] = min(diff[i], low);
        }

        for(int i = 0; i < n && k > 0; i++) {
            if(diff[i] == low) {
                diff[i]--;
                k--;
            }
        }

        long long ans = 0;
        for(int x : diff) {
            ans += 1LL * x * x;
        }

        return ans;
    }
};