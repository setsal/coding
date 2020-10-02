class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp = nums;
        int len = nums.size();
        for ( int i=0; i<len; i++ ) {
            nums[(i+k)%len] = tmp[i];
        }
       
    }
};