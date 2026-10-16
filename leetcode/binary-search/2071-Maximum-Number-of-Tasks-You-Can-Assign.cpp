class Solution {
private:
    bool canAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k){
        multiset<int> ava(workers.end() - k, workers.end()); //Select the k strongest workers
        
        for(int i=k-1; i>=0; i--){ //Assign k easiest tasks to k strongest workers
            auto it = ava.lower_bound(tasks[i]);

            if(it != ava.end()){
                ava.erase(it);
            }
            else{
                if(pills == 0){
                    return false;
                }

                it = ava.lower_bound(tasks[i] - strength);
                if(it == ava.end()){
                    return false;
                }

                ava.erase(it);
                pills--;
            }
        }

        return true;
    }

public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int low = 0, high = min(tasks.size(), workers.size());
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canAssign(tasks, workers, pills, strength, mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};