class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans = "";

        // ( isme baad me count add karnge and ) isme count phele add karenge
        for(char str : s){
            //When count is zero then we have not to add paranthesis in ans
            if(str == '('){
                if(cnt > 0){
                    ans += str;
                }
                cnt++;
            }
            else{ //str == ')'
                cnt--;
                if(cnt > 0){
                    ans += str;
                }
            }
        }
        return ans;
    }
};