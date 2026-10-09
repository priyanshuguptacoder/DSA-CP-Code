class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        stack<int> st;

        int ans = 0;
        int i = 0;

        while(i < n){
            if(s[i] == '('){
                st.push('(');
            }
            else{
                if(!st.empty() && st.top() == '('){
                    if(!st.empty() && i + 1 < n && s[i] == ')' && s[i+1] == ')'){
                        st.pop();
                        i++;
                    }
                    else if(!st.empty() && i < n && s[i] == ')'){
                        ans++;
                        st.pop();
                    }
                    
                }
                else{
                    if(st.empty() && i + 1 < n && s[i] == ')' && s[i+1] == ')'){
                        ans++;
                        i++;
                    }
                    else if(st.empty() && i < n && s[i] == ')'){
                        ans += 2;
                    }
                }
            }

            i++;
        }

        while(!st.empty()){
            ans += 2;
            st.pop();
        }

        return ans;
    }
};