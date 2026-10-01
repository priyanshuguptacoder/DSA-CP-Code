class Solution {
private:
    bool check(int idx, string& s, unordered_set<string>& set, vector<int>& dp){
        if(idx == s.length()){
            return true;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }
        int len = s.length();

        for(int i=idx+1; i<=len; i++){
            string word = s.substr(idx, i - idx); //Take substring from idx to i - 1

            if(set.count(word) && check(i, s, set, dp)){ //If word exists, check the remaining string
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<int> dp(n, -1); //In this -1 not calculated, 0 false, 1 true

        return check(0, s, set, dp);
    }
};