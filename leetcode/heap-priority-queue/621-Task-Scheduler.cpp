class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);

        for(char ch : tasks){
            mp[ch - 'A']++;
        }

        int time = 0;
        priority_queue<int> pq;
        
        for(int i=0; i<26; i++){
            if(mp[i] > 0){
                pq.push(mp[i]);
            }
        }

        while(!pq.empty()){
            vector<int> temp;

            for(int i=1; i<=n+1; i++){ //We are taking n + 1 beacuse n wating time and 1 khud ka bhi toh hai
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int f : temp){
                if(f > 0){
                    pq.push(f);
                }
            }

            if(pq.empty()){
                time += temp.size(); //Jaise ek hi baccha hai toh ham sme n + 1 size assign kar rahe time ka toh so wo khali wale hata denge because wo last me hai use baad koi bhi nahi hai
            }
            else{
                time += n + 1;
            }
        }

        return time;
    }
};