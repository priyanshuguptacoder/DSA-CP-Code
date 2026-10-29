class Solution {
private:
    int reverse(int n){
        int ans = 0;
        while(n){
            int dig = n % 10;
            ans = ans * 10 + dig;
            n /= 10;
        }

        return ans;
    }

public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();

        set<int> st(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            st.insert(reverse(nums[i]));
        }

        return st.size();
    }
};