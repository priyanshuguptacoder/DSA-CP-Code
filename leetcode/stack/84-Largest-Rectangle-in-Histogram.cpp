class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int maxArea = 0;

        for(int i=0; i<n; i++){
            int curr = height[i];

            while(!st.empty() && height[st.top()] > curr){
                int idx = st.top();
                st.pop();

                int h = height[idx];
                int w;
                if(st.empty()){
                    w = i;
                }
                else{
                    w = i - st.top() - 1;
                }
                int area = h * w;
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }

        while(!st.empty()){
            int idx = st.top();
            st.pop();

            int h = height[idx];
            int w;
            if(st.empty()){
                w = n;
            }
            else{
                w = n - st.top() - 1;
            }
            int area = h * w;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};