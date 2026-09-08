class Solution {
public:
    int countCommas(int n) {
        long long base = 1000;
        int ans = 0;
        
        while(base <= n){
            ans += n - base + 1;
            base *= 1000;
        }

        return ans;
    }
};