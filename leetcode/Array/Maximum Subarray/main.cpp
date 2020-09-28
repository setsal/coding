class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if ( nums.empty() ) {
            return 0;
        }
        
        int i = 0;
        int curMax = nums[0];
        int res = curMax;

        for ( i=1; i<nums.size(); i++ ) {
            if ( curMax > 0 ) {
                curMax += nums[i];
            } else {
                curMax = nums[i];
            }

            if ( curMax > res ) {
                res = curMax;
            }
        }
        return res;
    }
};