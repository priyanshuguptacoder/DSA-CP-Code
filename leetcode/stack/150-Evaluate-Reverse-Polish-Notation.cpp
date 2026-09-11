class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(string st : tokens){
            if(st == "+" || st == "-" || st == "*" || st == "/"){
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                
                int res;
                if(st == "+") res = a + b;
                else if(st == "-") res = a - b;
                else if(st == "*") res = a * b;
                else res = a / b;

                s.push(res);
            }
            else{
                s.push(stoi(st));
            }
        }
        return s.top();
    }
};