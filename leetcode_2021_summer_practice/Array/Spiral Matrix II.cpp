class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> result(n, vector<int>(n, 0));
        int startX = 0, startY = 0;
        
        int loop_circle = n / 2;   // loop circle, e.g 3 -> loop 1, 4 -> loop 2
        int middle = n / 2;        // for caculate middle value (if n is odd)
        
        int offset = 1;  // range for loop
        int count = 1;
        
        int i = 0, j = 0;
        
        while (loop_circle--) {
            i = startX;
            j = startY;
            
            // upper
            for (j = startY; j < startY + n - offset; j++) {
                result[startX][j] = count++;
            }
            
            // right
            for (i = startX; i < startX + n - offset; i++) {
                result[i][j]  = count++;
            }
            
            // bottom
            for (; j > startY; j--) {
                result[i][j] = count++;
            }
            
            // left 
            for( ; i > startX; i--) {
                result[i][j] = count++;
            }
            
            // every second loop
            startX++;
            startY++;
            
            offset += 2;
            
        }
        
        // odd middle value
        if (n % 2) {
            result[middle][middle] = count;    
        }
        return result;
    }
};