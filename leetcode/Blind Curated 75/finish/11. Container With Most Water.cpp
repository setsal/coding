class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int length = height.size();
        
        // Two pointer 
        int left = 0;
        int right = length - 1;
        
        int maxWater = 0;
        
        while (left < right) {
            
            int curMin = min(height[left], height[right]);
            maxWater = max(maxWater, curMin * (right - left));            
            
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }            
        
        }
        return maxWater;
    }
};