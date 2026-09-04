class Solution {
    long long MOD = 1e9 + 7;
private:
    long long modPower(long long a, long long b) {
        long long ans = 1;
        a %= MOD;

        while(b) {
            if(b & 1) ans = (ans * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }

        return ans;
    }

public:
    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        long long ans = 0;

        for(int i=0; i<n; i++){
            long long num = nums[i];

            int width = num % 10;
            long long d = floor(num / 10);
            string s = to_string(d);

            string fir = s.substr(0, width);
            long long x = stoll(fir);
            string sec = s.substr(width);
            long long y = stoll(sec);

            ans += modPower(x, y);
        }

        return ans % MOD;
    }
};