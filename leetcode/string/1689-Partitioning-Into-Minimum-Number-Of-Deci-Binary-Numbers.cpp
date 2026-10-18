class Solution {
public:
    int minPartitions(string n) {
        int maxDigit = -1;

        for(char ch : n){
            maxDigit = max(maxDigit, ch - '0');
        }

        return maxDigit;
    }
};