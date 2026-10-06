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

    int findMaximumXOR(vector<int>& nums) {
        Node* root = new Node();

        for(int num : nums){ //Insert all numbers to trie
            insert(root, num);
        }

        int ans = 0;
        for(int num : nums){ //FInd best XOR for every number
            ans = max(ans, getMaxXor(root, num));
        }

        return ans;
    }
};