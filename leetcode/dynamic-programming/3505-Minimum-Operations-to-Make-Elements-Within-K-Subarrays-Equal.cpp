class Solution {
    multiset<int> left, right;
    long long sumLeft = 0, sumRight = 0;
    int x;

private:
    void balance(){
        int requ = (x + 1) / 2;
        while(left.size() > requ){
            auto it = prev(left.end());
            int val = *it;

            sumLeft -= val;
            left.erase(it);

            right.insert(val);
            sumRight += val;
        }

        while(left.size() < requ && !right.empty()){
            auto it = right.begin();
            int val = *it;

            sumRight -= val;
            right.erase(it);

            left.insert(val);
            sumLeft += val;
        }
    }

    void add(int val){
        if(left.empty() || val <= *left.rbegin()){
            left.insert(val);
            sumLeft += val;
        }
        else{
            right.insert(val);
            sumRight += val;
        }
        
        balance();
    }

    void remove(int val){
        auto it = left.find(val);

        if(it != left.end()){
            sumLeft -= val;
            left.erase(it);
        }
        else{
            it = right.find(val);
            sumRight -= val;
            right.erase(it);
        }

        balance();
    }

    long long getCost(){
        long long median = *left.rbegin();

        return median * (long long)left.size() - sumLeft + sumRight - median * (long long)right.size();
    }
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        this -> x = x;
        int n = nums.size();

        vector<long long> cost(n-x+1);

        for(int i=0; i<x; i++){
            add(nums[i]);
        }

        cost[0] = getCost();
        for(int i=x; i<n; i++){
            remove(nums[i-x]);
            add(nums[i]);

            cost[i-x+1] = getCost();
        }

        const long long INF = 1e18;
        vector<long long> prev(n+1, 0);
        vector<long long> curr(n+1, INF);

        for(int j=1; j<=k; j++){
            fill(curr.begin(), curr.end(), INF);

            for(int i=1; i<=n; i++){
                curr[i] = curr[i - 1];

                if(i >= x && prev[i-x] != INF){
                    curr[i] = min(curr[i], prev[i-x] + cost[i-x]);
                }
            }
            swap(prev, curr);
        }

        return prev[n];
    }
};