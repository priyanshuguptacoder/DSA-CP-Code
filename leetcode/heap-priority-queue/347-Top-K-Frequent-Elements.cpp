class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp; //num, freq

        for(int x : nums){
            mp[x]++;
        }

        priority_queue<pair<int, int>> pq; //Max Heap
        for(auto& freq : mp){
            pq.push({freq.second, freq.first}); //First is freq , second is number
        }

        vector<int> temp;
        while(!pq.empty() && k--){
            int num = pq.top().second;
            pq.pop();

            temp.push_back(num);
        }

        return temp;
    }
};