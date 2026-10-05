class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0){
            return false;
        }

        map<int, int> mp;
        for(int x : hand){
            mp[x]++;
        }

        while(!mp.empty()){
            int st = mp.begin() -> first;

            for(int i=0; i<groupSize; i++){
                int x = st + i;
                if(mp.find(x) == mp.end()){ //Consecutive nahi ban pa raha hai toh tab group size nahi ban sakta
                    return false;
                }

                mp[x]--;
                if(mp[x] == 0){
                    mp.erase(x);
                }
            }
        }

        return true;
    }
};