class Solution {
public:
    int firstStableIndex(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> prefixMax(n);
        vector<int> suffixMin(n);

        prefixMax[0] = arr[0];
        suffixMin[n-1] = arr[n-1];

        for(int i=n-2; i>=0; i--){
            suffixMin[i] = min(suffixMin[i+1], arr[i]);
        }

        for(int i=1; i<=n-1; i++){
            prefixMax[i] = max(arr[i], prefixMax[i-1]);
        }

        for(int i=0; i<=n-1; i++){
            int diff = prefixMax[i] - suffixMin[i];
            if(diff <= k){
                return i;
                break;
            }
        }
        return -1;
    }
};