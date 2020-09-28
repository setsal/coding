class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if ( nums.empty() ) {
            return 0;
        }
        int i;
        for ( i=0; i<nums.size(); i++ ) {
                if ( nums[i] == target || nums[i] > target  ) {
                    break;
                } 
        }
        return i;
    }   
};