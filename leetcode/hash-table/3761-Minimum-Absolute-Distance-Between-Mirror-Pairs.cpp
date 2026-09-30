class Solution {
private:
    int reverse(int n){
        string s = to_string(n);
        string ans = "";

        for(int i=s.length()-1; i>=0; i--){
            if(ans.length() == 0 && s[i] == '0'){
                continue;
            }
            ans += s[i];
        }

        int num = stoi(ans);
        return num;
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
    
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            if(mp.find(nums[i]) != mp.end()){ //for that indeex same value is present before
                int j = mp[nums[i]];
                mini = min(mini, abs(j - i));
            }

            mp[reverse(nums[i])] = i;
        }

        return (mini == INT_MAX ? -1 : mini);
    }
};