class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int middle = (left + right) / 2;
            
            if (nums[middle] == target) {
                return middle;
            }
            
            // binary search with edge case
            if (nums[middle] >= nums[left]) {
                
                if (target < nums[middle] && target >= nums[left]) {
                    right = middle - 1;
                }
                else {
                    left = middle + 1;
                }
            }
            else {
                if (target > nums[middle] && target <= nums[right]) {
                    left = middle + 1;
                }
                else {
                    right = middle - 1;
                }
            }
        }
        
        return -1;
    }
};