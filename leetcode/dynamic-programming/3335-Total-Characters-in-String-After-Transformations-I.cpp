class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<int> cnt(26, 0);

        for(char c : s){
            cnt[c - 'a']++;
        }

        while(t--){
            vector<int> next(26, 0);
            for(int i=0; i<25; i++){
                next[i+1] = cnt[i]; //String ek character se badh gaya hai
            }

            next[0] = cnt[25]; //z a aur b dono ban jayega aur previous me 'a' -> 'b' ban gaya hai
            next[1] = (next[1] + cnt[25]) % MOD; //z b bhi banega aur phele ka 'a' 'b' bana hai usse bhi add kara hai phele
            cnt = next;
        }

        int ans = 0;
        for(int i=0; i<26; i++){
            ans = (ans + cnt[i]) % MOD;
        }

        return ans;
    }
};