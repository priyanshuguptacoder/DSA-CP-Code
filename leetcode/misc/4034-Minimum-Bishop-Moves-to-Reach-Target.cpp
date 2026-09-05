class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0];
        int sc = source[1];
        int tr = target[0];
        int tc = target[1];

        if ((sr + sc) % 2 != (tr + tc) % 2){ // Different colors → impossible
            return -1;
        }

        
        if (abs(sr - tr) == abs(sc - tc)){ // Same diagonal → one move
            return 1;
        }

        return 2; // Same color, different diagonal → two moves
    }
};