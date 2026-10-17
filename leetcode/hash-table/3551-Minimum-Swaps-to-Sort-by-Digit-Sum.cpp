class Solution {
private:
    int digSum(int num){
        int sum = 0;

        while(num != 0){
            int dig = num % 10;
            sum += dig;
            num /= 10;
        }
        
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp; //num, original idx

        for(int i=0; i<n; i++){
            mp[nums[i]] = i;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if(digSum(a) != digSum(b)){
                return digSum(a) < digSum(b);
            }

            return a < b;
        });

        vector<bool> vis(n, false);
        int swaps = 0;

        for(int i=0; i<n; i++){
            if(vis[i]){
                continue;
            }

            int j = i;
            int cycle = 0;
            while(!vis[j]){
                vis[j] = true;
                j = mp[nums[j]];
                cycle++;
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
};