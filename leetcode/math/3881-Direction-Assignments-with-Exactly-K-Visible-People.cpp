class Solution {
    static constexpr long long MOD = 1000000007LL;
    vector<long long> fact, invFact;

private:
    long long power(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    void precompute(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);

        fact[0] = 1;

        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[n] = power(fact[n], MOD - 2);

        for (int i = n; i >= 1; i--) {
            invFact[i - 1] = invFact[i] * i % MOD;
        }
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n)
            return 0;

        return fact[n] * invFact[r] % MOD
                     * invFact[n - r] % MOD;
    }

public:
    int countVisiblePeople(int n, int pos, int k) {
        int total = n - 1;

        if (k > total)
            return 0;

        int r = min(k, total - k);

        precompute(total);

        return 2LL * nCr(total, r) % MOD;
    }
};