class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        int left = 0, ans = n + 1;
        long long sum = 0;

        for(int right=0; right<n; right++){
            if(freq[nums[right]] == 0){
                sum += nums[right];
            }

            freq[nums[right]]++;
            while(sum >= k){
                ans = min(ans, right - left + 1);
                freq[nums[left]]--;

                if(freq[nums[left]] == 0){
                    sum -= nums[left];
                }
                left++;
            }
        }

        return ans == n + 1 ? -1 : ans;
    }
};