class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for(int num : digits){
            freq[num]++;
        }
        
        int ans = 0;
        for(int i=1; i<=9; i++){ //Hundred digit cannot be 0
            if(freq[i] == 0){
                continue;
            }
            freq[i]--;

            for(int j=0; j<=9; j++){ //Any digit on tens place
                if(freq[j] == 0){
                    continue;
                }
                freq[j]--;

                for(int k=0; k<=8; k+=2){ //Only even number on ones place
                    if(freq[k] > 0){
                        ans++;
                    }
                }
                freq[j]++;
            }
            freq[i]++;
        }

        return ans;
    }
};