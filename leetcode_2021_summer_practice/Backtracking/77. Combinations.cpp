class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        // start from 1 ... n
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i);
            backtracking(n, k, i+1);
            path.pop_back();
        }

    }

public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }
};