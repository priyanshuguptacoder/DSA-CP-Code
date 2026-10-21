class Solution {
public:
    int minOperations(string s) {
        string t = s;
        sort(t.begin(), t.end());

        if(s == t){
            return 0;
        }

        int n = s.length();
        if(n == 2){
            return -1;
        }

        char mini = t[0];
        char maxi = t[n-1];
        
        if(s[0] == mini || s[n-1] == maxi){
            return 1;
        }

        for(int i=1; i<n-1; i++){
            if(s[i] == mini || s[i] == maxi){ //Minimum and maximum appears in middle
                return 2;
            }
        }

        return 3; //Both extreme are stuck at wrong end
    }
};