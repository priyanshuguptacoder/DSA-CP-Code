class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0, j = 0;
        int currSum = 0;
        vector<int> minLenTillIdx(n, INT_MAX);

        int bestMinLen = INT_MAX;
        int result = INT_MAX;
        while(j < n){
            currSum += arr[j];

            while(i < j && currSum > target){
                currSum -= arr[i++];
            }

            if(currSum == target){
                int len = j - i + 1;
                if(i > 0 && minLenTillIdx[i-1] != INT_MAX){
                    result = min(result, len + minLenTillIdx[i-1]);
                }

                bestMinLen = min(bestMinLen, len);
            }

            minLenTillIdx[j] = bestMinLen;
            j++;
        }

        return result == INT_MAX ? -1 : result;
    }
};