class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.length();
        int len = n / k;

        unordered_map<string, int> freq;
        for(int i=0; i<n; i+=len){
            freq[s.substr(i, len)]++;
        }

        for(int i=0; i<n; i+=len){
            freq[t.substr(i, len)]--;
        }
        
        for(auto u : freq){
            if(u.second != 0){
                return false;
            }
        }

        return true;
    }
};