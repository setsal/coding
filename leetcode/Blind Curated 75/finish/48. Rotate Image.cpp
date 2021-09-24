class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int length = matrix.size();
        
        // do transform 
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // reverse
        for (int i = 0; i < length; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    
    }
};