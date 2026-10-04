class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        const long long NEG = LLONG_MIN / 4;
        long long a0 = NEG, a1 = NEG;
        long long p0 = NEG, p1 = NEG;
        long long b0 = NEG, b1 = NEG;

        long long ans = NEG;
        for(int v : nums){
            long long x = v;

            long long n0 = max(x, a1 + x); //No deletion
            long long n1 = a0 - x;

            long long m0 = max(b1, p1) + x; //One deletion
            long long m1 = max(b0, p0) - x;

            ans = max({ans, n0, n1, m0, m1});
            
            p0 = a0; //Move ahead
            p1 = a1;
            a0 = n0;
            a1 = n1;
            b0 = m0;
            b1 = m1;
        }

        return ans;
    }
};