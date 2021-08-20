class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                continue;   // first element after sort is zero will not always combine to three element;
            }
            
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (right > left) {
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                }   
                else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                }
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    
                    right--;
                    left++;
                }
            }
        }
        return result;
        
    }
};







// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> result;
//         sort(nums.begin(), nums.end());
        
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] > 0) {
//                 continue;   // first element after sort is zero will not always combine to three element;
//             }
            
//             if (i > 0 && nums[i] == nums[i - 1]) {
//                 continue;
//             }
            
//             unordered_set<int> set;
            
//             for (int j = i + 1; j < nums.size(); j++) {
//                 if (j > i + 2 && nums[j] == nums[j-1] && nums[j-1] == nums[j-2]) {
//                     continue;
//                 }
                
//                 int c = 0 - (nums[i] + nums[j]);
//                 if (set.find(c) != set.end()) {
//                     result.push_back({nums[i], nums[j], c});
//                     set.erase(c);
//                 } else {
//                     set.insert(nums[j]);
//                 }
//             }
//         }
//         return result;
        
//     }
// };