class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        if((source[1] + source[0]) % 2 != (target[1] + target[0]) % 2){ //If both not on same colour then not possible
            return -1;
        }

        if((source[0] + source[1] == target[0] + target[1]) || (source[1] - source[0] == target[1] - target[0])){
            return 1;
        }
        else{
            return 2;
        }
    }
};