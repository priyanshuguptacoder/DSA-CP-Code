class Solution {
public:
    int minOperations(int k) {
        int x = ceil(sqrt(k));

        int copy = (k + x - 1) / x;
        return (x - 1) + (copy - 1);
    }
};