class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();
        vector<long long> count(24);

        long long ans = 0;
        for(int i=0; i<n; i++){
            ans += count[(24 - (hours[i] % 24)) % 24];
            count[hours[i] % 24]++;
        }

        return ans;
    }
};