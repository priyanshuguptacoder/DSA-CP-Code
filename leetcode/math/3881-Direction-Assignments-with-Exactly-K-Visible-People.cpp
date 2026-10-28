class Solution {
    long long MOD = 1e9 + 7;
private:
    long long power(long long a, long long b){
        long long ans = 1;

        while(b > 0){
            if(b % 2){
                ans = (ans * a) % MOD;
            }

            a = (a * a) % MOD;
            b /= 2;
        }

        return ans;
    }
    
public:
    int countVisiblePeople(int n, int pos, int k) {
        int total = n - 1;
        int r = min(k, total - k);

        long long num = 1, den = 1;
        for(int i=1; i<=r; i++){
            num = num * (total - r + i) % MOD;
            den = (den * i) % MOD;
        }

        long long comb = num * power(den, MOD - 2) % MOD;
        return 2 * comb % MOD;
    }
};