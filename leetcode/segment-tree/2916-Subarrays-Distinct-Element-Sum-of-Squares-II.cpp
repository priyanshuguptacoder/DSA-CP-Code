class Solution {
    static const int MOD = 1e9 + 7;
    
    struct Node{
        long long sum = 0;
        long long sqSum = 0;
        long long lazy = 0;
    };
    
    vector<Node> tree;
    int n;
    
private:
    void apply(int node, int l, int r, long long x){
        long long len = r - l + 1;
        
        tree[node].sqSum = (tree[node].sqSum + 2LL * x * tree[node].sum + len * x % MOD * x) % MOD;
        
        tree[node].sum = (tree[node].sum + len * x) % MOD;
        
        tree[node].lazy = (tree[node].lazy + x) % MOD;
    }
    
    void push(int node, int l, int r){
        if(tree[node].lazy == 0 || l == r){
            return ;
        }
        
        int mid = (l + r) / 2;
        long long x = tree[node].lazy;
        
        apply(node * 2, l, mid, x);
        apply(node * 2 + 1, mid + 1, r, x);
        
        tree[node].lazy = 0;
    }
    
    void update(int node, int l, int r, int ql, int qr){
        if(qr < l || r < ql){
            return ;
        }
        
        if(ql <= l && r <= qr){
            apply(node, l, r, 1);
            return ;
        }
        
        push(node, l, r);
        int mid = l + (r - l) / 2;
        
        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);
        
        tree[node].sum = (tree[node * 2].sum + tree[node * 2 + 1].sum) % MOD;
        
        tree[node].sqSum = (tree[node * 2].sqSum + tree[node * 2 + 1].sqSum) % MOD;
    }
    
public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4*n+5, Node());
        
        vector<int> last(100001, -1);
        long long ans = 0;
        
        for(int i=0; i<n; i++){
            int k = last[nums[i]] + 1;
            
            update(1, 0, n-1, k, i);
            
            ans = (ans + tree[1].sqSum) % MOD;
            last[nums[i]] = i;
        }
        
        return ans;
    }
};