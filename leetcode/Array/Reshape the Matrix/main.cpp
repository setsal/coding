class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums[0].size(), n=nums.size();  // M * N matrix;
        if ( r*c != m*n ) { // invalid transfer
            return nums; 
        }

        // column
        vector<int> col;
        col.assign(c,0); 

        vector<vector<int>> reNums;
        reNums.assign(r,col);

        for ( int i=0; i<m*n; i++ ) {
            reNums[i/c][i%c] = nums[i/m][i%m];
        }

        return reNums;
    }
};