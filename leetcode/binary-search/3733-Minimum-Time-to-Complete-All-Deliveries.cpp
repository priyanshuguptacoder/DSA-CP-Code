class Solution {
private:
    bool possible(long long T, vector<int>& d, vector<int>& r) {
        long long r1 = r[0];
        long long r2 = r[1];
        long long lcm = r1 / gcd(r1, r2) * r2;
        
        long long only1 = T / r2 - T / lcm; //Only drone 1 can work
        long long only2 = T / r1 - T / lcm; //Only drone 2 can work
        long long both = T - T / r1 - T / r2 + T / lcm;  //Both drones can work

        long long need1 = max(0LL, (long long)d[0] - only1); //Remaining deliveries that need shared slots
        long long need2 = max(0LL, (long long)d[1] - only2);

        return need1 + need2 <= both;
    }

public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long low = 1;
        long long high = 1e18;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (possible(mid, d, r)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};