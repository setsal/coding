class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int cur = 0, sum = 0;

        //int sum = accumulate(nums.begin(), nums.end(), 0);  -> could be better
        for ( auto num : nums ) sum+=num;

        for ( int i=0; i<nums.size(); i++ ) {
            if ( sum-nums[i] == 2*cur )
                return i;
            cur += nums[i];
        }

        return -1;
    }
};