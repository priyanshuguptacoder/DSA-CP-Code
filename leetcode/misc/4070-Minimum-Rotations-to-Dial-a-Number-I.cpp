class Solution {
public:
    int minRotations(string s) {
        int ans = 0;
        int curr = 0;

        for(char ch : s){
            int next = ch - '0';
            int dist = abs(curr - next);

            ans += min(dist, 10 - dist); //Because circular is given so 10 - dist
            curr = next;
        }

        return ans;
    }
};