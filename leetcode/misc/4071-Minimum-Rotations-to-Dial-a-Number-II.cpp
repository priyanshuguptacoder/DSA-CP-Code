class Solution {
private:
    int cost(int a, int b){
        int d = abs(a - b);
        return min(d, 10 - d); //Beacuse it is circular so 10 - d
    }
    
public:
    int minRotations(int n, string s) {
        int orig = cost(0, s[0] - '0'); //Cost without reversing anything

        for(int i=1; i<n; i++){
            orig += cost(s[i - 1] - '0', s[i] - '0');
        }

        int ans = orig;
        for(int k=0; k<n; k++){ //Try reversing starting from k
            int prev = (k == 0) ? 0 : s[k - 1] - '0';
            int newCost = orig - cost(prev, s[k] - '0') + cost(prev, s[n-1] - '0'); //Remove old connections

            ans = min(ans, newCost);
        }

        return ans;
    }
};