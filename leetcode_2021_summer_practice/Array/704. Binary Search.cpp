class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int middle = 0;
        
        while ( left <= right ) {
            middle = (left + right)/2;    
            if ( nums[middle] == target ) {
                return middle;
            }
            else if ( nums[middle] > target ) {
                right = middle - 1;
            }
            else if ( nums[middle] < target ) {
                left = middle + 1;
            }
        }
        return -1;
    }
};