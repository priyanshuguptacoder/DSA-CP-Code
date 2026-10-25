class Solution {
public:
    int calculateScore(int a, int b) {
        int s1 = __builtin_popcount(a); //Number of set bits
        int s2 = __builtin_popcount(b);

        if(s1 >= s2){
            return s1 * s2;
        }
        else{
            return s2 / s1;
        }

        return -1;
    }
};