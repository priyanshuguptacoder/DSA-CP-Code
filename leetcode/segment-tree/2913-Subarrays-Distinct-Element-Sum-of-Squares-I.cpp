class Solution {
private:
    int sum(vector<int>& nums, int i, int j){
        set<int> s;
        for(int x=i; x<=j; x++){
            s.insert(nums[x]);
        }

        return s.size();
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int cnt = sum(nums, i, j);
                ans += (cnt * cnt);
            }
        }

        return ans;
    }
};