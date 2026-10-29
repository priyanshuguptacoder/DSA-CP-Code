class Solution {
private:
    long long lcmll(long long a, long long b){
        return (a / gcd(a, b)) * b;
    }

public:
    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> suffGCD(n+1, 0);
        vector<long long> suffLCM(n+1, 1);

        for(int i=n-1; i>=0; i--){ //Build suffix GCD and LCM
            suffGCD[i] = gcd(suffGCD[i+1], (long long)nums[i]);
            suffLCM[i] = lcmll(suffLCM[i+1], (long long)nums[i]);
        }

        long long ans = suffGCD[0] * suffLCM[0]; //Score without removing any element
        long long prefGCD = 0;
        long long prefLCM = 1;

        for(int i=0; i<n; i++){ //try removing each element
            long long g = gcd(prefGCD, suffGCD[i+1]);
            long long l = lcmll(prefLCM, suffLCM[i+1]);

            ans = max(ans, g * l);

            prefGCD = gcd(prefGCD, (long long)nums[i]); //Include nums[i] in the pref for the next iteration
            prefLCM = lcmll(prefLCM, nums[i]);
        }

        return ans;
    }
};