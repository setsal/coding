class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int ptr = 0;
        for ( int i=0; i<len; i++ ) {
            if ( nums[i] != 0 ) {
                nums[ptr] = nums[i];
                ptr++;
            }
        }

        for ( int i=ptr; i<len; i++ ) {
            nums[i] = 0;
        }
    }
};