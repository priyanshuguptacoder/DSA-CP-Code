class Solution {
private:
    long long fib(long long n, vector<long long>& dp){
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    }
    
public:
    bool threeFibonacciSum(int n) {
        if(n <= 0 || n % 2 != 0){
            return false;
        }

        n /= 2;
        vector<long long> dp(50, -1);
        for(int i=0; i<50; i++) {
            long long f = fib(i, dp);
            if (f == n) {
                return true;
            }
            if (f > n) {
                return false;
            }
        }

        return false;
    }
};