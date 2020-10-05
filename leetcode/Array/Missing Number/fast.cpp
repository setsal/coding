class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if ( nums.size() == 0 ) return {};
        
        int sum = 0;
        int len = nums.size();
        for ( auto num: nums ) {
            sum += num;
        }
        return 1/2*len*(len+1) - sum;
    }
};