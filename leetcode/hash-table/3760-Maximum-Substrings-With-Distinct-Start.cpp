class Solution {
public:
    int maxDistinct(string s) {
        int n = s.length();
        set<char> st;

        for(int i=0; i<n; i++){
            st.insert(s[i] - 'a');
        }

        return st.size();
    }
};