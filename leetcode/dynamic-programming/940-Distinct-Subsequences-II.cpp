class Solution {
    int MOD = 1e9 + 7;
    int dp[2001];
    vector<int> prev;
private:
    int solve(int n){
        if(n == 0){ //Empty subsequences
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int total = (2LL * solve(n-1)) % MOD; //Take current character and don't take current character
        if(prev[n] != 0){ //Phele ye wala character kabhi dekha hai
            int duplicates = solve(prev[n] - 1);
            total = (total - duplicates + MOD) % MOD;
        }

        return dp[n] = total;
    }

public:
    int distinctSubseqII(string s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        prev.assign(n+1, 0);

        vector<int> lastSeen(26, 0);
        for(int i=1; i<=n; i++){
            int idx = s[i-1] - 'a'; //For making 0 based indexing
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }

        return (solve(n) - 1 + MOD) % MOD; //Problem did not count empty subsequences
    }
};