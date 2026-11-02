class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 1){
            if(nums1[0] == nums2[0]){
                return 0;
            }
            else{
                return nums2[0] - nums1[0];
            }
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int num = nums2[0] - nums1[0];
        for(int i=1; i<nums1.size(); i++){
            if(nums2[i] - nums1[i] != num){
                return -1;
            }
        }
        return num;
    }
};