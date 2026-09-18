class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> start(26, -1), end(26, 0);
        vector<bool> isValid(26, true);
        vector<string> result;
        
        for(int i = 0; i < n; i++){ //Find first and last occurrence of every character
            int c = s[i] - 'a';
            if(start[c] == -1) {
                start[c] = i;
            }
            end[c] = i;
        }
        
        for(int c = 0; c < 26; c++){ //Check validity of every character's range
            if(start[c] == -1) continue;

            for(int i = start[c]; i <= end[c]; i++){
                int x = s[i] - 'a';
                if(start[x] < start[c]){
                    isValid[c] = false;
                    break;
                }

                end[c] = max(end[c], end[x]);
            }
        }

        int lastTakenStart = INT_MAX;
        for(int i = n - 1; i >= 0; i--){ //Take maximum number of non-overlapping substrings
            int c = s[i] - 'a';
            if(!isValid[c]) continue;

            if(i == start[c] && end[c] < lastTakenStart){
                result.push_back(s.substr(i, end[c] - i + 1));
                lastTakenStart = i;
            }
        }

        return result;
    }
};