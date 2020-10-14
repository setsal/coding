class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        // check empty
        if ( M.empty() || M[0].empty() ) return {};

        // get length
        int row = M.size();
        int col = M[0].size();

        // create the same vector as M
        vector<vector<int>> res = M;

        // create 8 move position 上 下 左 右 上左 上右 下左 下右
        vector<vector<int>> moves = {{-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
        
        for ( int i=0; i<row; i++ ) {
            for ( int j=0; j<col; j++ ) {
                int cur_i = i, cur_j = j, cnt = M[i][j], times = 1;
                for( auto move : moves ) {
                    if ( cur_i+move[0] < 0 || cur_j+move[1]<0 || cur_i+move[0] >= row || cur_j+move[1] >= col ) continue;
                    times++;
                    cnt += M[cur_i+move[0]][cur_j+move[1]];
                }
                res[i][j] = cnt/times;
            }
        }
        return res;
    }
};