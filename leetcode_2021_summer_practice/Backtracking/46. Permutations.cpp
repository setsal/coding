class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        int length = nums.size(); // 3
        
        vector<vector<int>> res;
        
        if (length == 1) {
            res.push_back(nums);
            return res;
        }
    
        
        for (int i = 0; i < length; i++) {
            
            vector<vector<int>> tmpRes;
            vector<int> tmp2;
            
            for (int k = 0; k < length; k++) {
                if (i == k) {
                    continue;
                }
                tmp2.push_back(nums[k]);
            }
            // tmp2.assign(nums.begin() + i + 1, nums.end());  // [2, 3]
            
            
            tmpRes = permute(tmp2);  // get [2,3] [3,2]
            
            // get the result after 
            for (int j = 0; j < tmpRes.size(); j++) { 
                tmpRes[j].insert(tmpRes[j].begin(), nums[i]); // first element;
                res.push_back(tmpRes[j]);
            }  // [1, 2, 3] [1, 3, 2]
            
        }
        return res;
    }
};