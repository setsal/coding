class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if ( nums.size() == 0 ) return 0;
        if ( nums.size() == 1 ) return 1;
        
        int res = 0, cnt = 1, cur = nums[0];
        for ( int i=1; i<nums.size(); i++ ) {
            if ( nums[i] > cur ) {
                cnt++;
            } else {
                cnt = 1;
            }
            res = max(res, cnt);
            cur = nums[i];
        }
        return res;
    }
};