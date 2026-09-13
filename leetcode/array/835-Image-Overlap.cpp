class Solution {
private:
    int countOverLap(vector<vector<int>>& img1, vector<vector<int>>& img2, int row, int col){
        int n = img1.size();
        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                //Find indices from B[i] from A[i] i.e. B[i][j] => A[i+rowOffSet][j+colOffSet]
                int bi = i + row;
                int bj = j + col;

                if(bi < 0 || bi > n - 1 || bj < 0 || bj > n - 1){
                    continue;
                }
                if(img1[i][j] == 1 && img2[bi][bj] == 1){
                    count++;
                }
            }
        }

        return count;
    }

public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxOverLap = 0;

        for(int r=-n+1; r<=n-1; r++){ //Here r is rowOffset
            for(int c=-n+1; c<=n-1; c++){ //Here c is columnOffset

                int count = countOverLap(img1, img2, r, c);
                maxOverLap = max(maxOverLap, count);
            }
        }
        return maxOverLap;
    }
};