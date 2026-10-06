class Solution {
public:
    struct Node{
        Node* child[2]; //2 Ka hi child bana rahe hai because ham bit me 0 aur 1 hi store kar rahe hai

        Node(){
            child[0] = child[1] = nullptr;
        }
    };

    void insert(Node* root, int num){
        Node* curr = root;

        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(curr -> child[bit] == nullptr){
                curr -> child[bit] = new Node();
            }

            curr = curr -> child[bit];
        }
    }

    int getMaxXor(Node* root, int num){
        Node* curr = root;
        int ans = 0;

        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;
            int opposite = 1 - bit; //We want to make opposite bit to get maximum xor

            if(curr -> child[opposite] != nullptr){ //If that bit possible then take it if not then take same bit
                ans |= (1 << i);
                curr = curr -> child[opposite];
            }
            else{
                curr = curr -> child[bit];
            }
        }

        return ans;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        //We cannot insert all nums at once, For each query [x, m] only numbers <= m are allowed
        sort(nums.begin(), nums.end());

        vector<tuple<int, int, int>> q; //{m, x, original_index}
        for(int i=0; i<queries.size(); i++){
            int x = queries[i][0];
            int m = queries[i][1];

            q.push_back({m, x, i});
        }

        sort(q.begin(), q.end()); //Sort queries according to m
        vector<int> ans(queries.size(), -1);
        
        Node* root = new Node();
        int j = 0;
        for(auto [m, x, index] : q){
            while(j < nums.size() && nums[j] <= m){ //Insert only numbers <= m
                insert(root, nums[j]);
                j++;
            }

            if(j == 0){ //No valid number exists
                ans[index] = -1;
            }
            else{
                ans[index] = getMaxXor(root, x);
            }
        }

        return ans;
    }
};