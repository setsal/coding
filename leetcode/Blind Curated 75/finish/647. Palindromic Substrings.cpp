class Solution {
public:
    int countSubstrings(string s) {
        
        int length = s.size();
        int res = 0;
        // init vector
        vector<vector<bool>> dp(length, vector<bool>(length, false));
        
        for (int i = length - 1; i >= 0; i--) {
            for (int j = i; j < length; j++) {
                // cout << i << " " << j << endl;
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        res++;
                        dp[i][j] = true;
                    }   
                    else if (dp[i + 1][j - 1]) {
                        res++;
                        dp[i][j] = true;
                    }
                }
                
            }
        }
        return res;
        
        // return 1;
        
    }
};