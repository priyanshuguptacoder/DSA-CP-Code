class Solution {
    typedef long long ll;
    int MOD = 1e9 + 7;

    ll findPower(ll a, ll base) {
        if (base == 0) {
            return 1;
        }

        ll half = findPower(a, base / 2);
        ll result = (half * half) % MOD;
        if (base % 2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }

    bool check(vector<int>& nums, int size, ll base) {
        int n = nums.size();
        unordered_map<ll, int> mp;

        ll hash = 0;
        ll p = findPower(base, size - 1); // Calculate base^(size - 1) % MOD

        int i = 0;
        int j = 0;

        while (j < n) {
            hash = (hash * base + nums[j]) % MOD; 
            if (j - i + 1 < size) {
                j++;
            } else {
                mp[hash]++;
                hash = (hash - (p * nums[i]) % MOD + MOD) % MOD;

                i++;
                j++;
            }
        }

        for (auto& [key, count] : mp) {
            if (count == 1) {
                return true;
            }
        }

        return false;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        ll base = *max_element(begin(nums), end(nums)) + 1;

        int l = 1;
        int r = n;
        int result = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(nums, mid, base)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }
};