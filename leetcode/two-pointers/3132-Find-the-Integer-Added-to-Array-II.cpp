class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int n = nums1.size();
        int m = nums2.size();

        int ans = INT_MAX;
        for(int i=0; i<3; i++){ //After sorting nums2 first element correspond to one of first three elements of nums1
            int x = nums2[0] - nums1[i];

            int p1 = 0, p2 = 0;
            int removed = 0;

            while(p1 < n && p2 < m){
                if(nums1[p1] + x == nums2[p2]){
                    p1++;
                    p2++;
                }
                else if(nums1[p1] + x < nums2[p2]){
                    p1++;
                    removed++;
                }
                else{ //First element if far greater than second array so break the loop and check next element of nums1
                    removed = 3;
                    break;
                }
            }

            removed += (n - p1);
            if(removed == 2){
                ans = min(ans, x);
            }
        }

        return ans;
    }
};