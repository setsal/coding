class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for( int i=0; i<nums.size(); i++ ) {
            res += nums[i];
            i++;
        }
        return res;
    }
};