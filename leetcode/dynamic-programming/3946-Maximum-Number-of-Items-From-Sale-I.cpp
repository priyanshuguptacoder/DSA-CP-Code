class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        const int NEG = -1e9;

        vector<int> dp(budget+1, NEG);
        dp[0] = 0;

        for(int i=0; i<n; i++){
            int f = items[i][0];
            int p = items[i][1];

            int bonus = 0; //Calculate free copies
            for(int j=0; j<n; j++){
                if(i != j && items[j][0] % f == 0){
                    bonus++;
                }
            }

            vector<int> take(budget+1, NEG);
            for(int c=p; c<=budget; c++){ //Buy first copy
                if(dp[c-p] != NEG){
                    take[c] = max(take[c], dp[c-p]+ bonus + 1);
                }
                if(take[c-p] != NEG){ //Buy additional copy
                    take[c] = max(take[c], take[c-p]+1);
                }
            }

            for(int c=0; c<=budget; c++){ //Either skip or purchase current item
                dp[c] = max(dp[c], take[c]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};