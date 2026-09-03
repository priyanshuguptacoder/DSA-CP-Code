class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = *min_element(nums1.begin(), nums1.end());

        if(mini % 2 == 1){ //If minimum is odd then we can convert all even to odd then all nums2 will be odd
            return true;
        }

        for(int num : nums1){ //Check we can make all even
            if(num % 2 == 1){
                return false;
            }
        }

        return true; //All nums2 will be even
    }
};