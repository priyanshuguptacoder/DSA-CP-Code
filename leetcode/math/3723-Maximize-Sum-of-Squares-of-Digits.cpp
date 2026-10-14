class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num * 9 < sum){
            return "";
        }

        string s = "";
        for(int i=0; i<num; i++){
            if(sum >= 9){
                s.push_back('9');
                sum -= 9;
            }
            else if(sum < 9 && sum > 0){
                s.push_back(sum + '0');
                sum = 0;
            }
            else{
                s.push_back('0');
            }
        }
        
        return s;
    }
};