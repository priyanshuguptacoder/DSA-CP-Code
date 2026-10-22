class Solution {
    unordered_set<string> dict;
    vector<string> dp[301];

private:
    vector<string> solve(string& s, int idx){
        if(idx == s.length()){
            return {""};
        }

        if(!dp[idx].empty()){
            return dp[idx];
        }

        vector<string> ans;
        string word;
        for(int i=idx; i<s.length(); i++){
            word += s[i];

            if(dict.count(word)){
                vector<string> suffix = solve(s, i+1);

                for(string suff : suffix){
                    if(suff.empty()){
                        ans.push_back(word);
                    }
                    else{
                        ans.push_back(word + " " + suff);
                    }
                }
            }
        }

        return dp[idx] = ans;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict.clear();

        for(string word : wordDict){
            dict.insert(word);
        }

        for(int i=0; i<=s.length(); i++){
            dp[i].clear();
        }

        return solve(s, 0);
    }
};