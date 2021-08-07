class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int i = 0;
        int sum = 0, subLength = 0;
        
        for (int j=0; j<nums.size(); j++) {
            sum += nums[j];
            
            while (sum >= target) {
                subLength = j - i + 1;
                result = result > subLength ? subLength : result;
                sum -= nums[i];
                i++;
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};