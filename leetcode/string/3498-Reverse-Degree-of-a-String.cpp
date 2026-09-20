class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int ans = 0;
        
        for(int i=0; i<n; i++){
            int ch = abs(s[i] - 'z') + 1;

            ans += (i + 1) * ch;
        }

        return ans;
    }
};