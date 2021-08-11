class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 0; i < coins.size(); i++) {        // traversal coins
            for (int j = coins[i]; j <= amount; j++) {   // traversal backpacks
                if (dp[j - coins[i]] != INT_MAX) {
                    dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
                }
            }    
        }
        
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};