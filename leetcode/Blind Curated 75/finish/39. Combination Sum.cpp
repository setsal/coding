class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        
        for (int i = startIndex; i < candidates.size(); i++) {
            if (sum + candidates[i] > target) {
                break;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i);
            
            // restore
            sum -= candidates[i];
            path.pop_back();
        }
    }
    

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        
        return result;
    }
};