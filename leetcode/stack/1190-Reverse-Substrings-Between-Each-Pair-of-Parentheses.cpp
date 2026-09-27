class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string temp = "";

        for(char ch : s){
            if(ch == '('){
                st.push(temp);
                temp = "";
            }
            else if(ch == ')'){
                reverse(temp.begin(), temp.end());

                temp = st.top() + temp;
                st.pop();
            }
            else{
                temp += ch;
            }
        }

        return temp;
    }
};