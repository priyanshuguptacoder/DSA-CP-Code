class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;

        for(int center=0; center<n; center++){
            int l = center; //Odd length palindrome their will n center 
            int r = center;

            while(l >= 0 && r < n && s[l] == s[r]){
                ans++;
                l--;
                r++;
            }

            l = center; //Even length palindrome their will n - 1 center 
            r = center + 1;

            while(l >= 0 && r < n && s[l] == s[r]){
                ans++;
                l--;
                r++;
            }
        }

        return ans;
    }
};