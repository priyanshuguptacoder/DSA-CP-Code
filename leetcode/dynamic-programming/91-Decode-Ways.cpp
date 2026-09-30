class Solution {
private:
    int decode(string& s, int idx, int n, vector<int>& dp){
        if(idx >= n){
            return 1;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int ways = 0;
        if(s[idx] != '0'){ //Take single digit
            ways += decode(s, idx+1, n, dp);
        }

        if(idx + 1 < n && ((s[idx] == '1' || s[idx] == '2' && s[idx+1] <= '6'))){ //Double digit decoding
            ways += decode(s, idx+2, n, dp);
        }

        return dp[idx] = ways;
    }
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);
        return decode(s, 0, n, dp);
    }
};