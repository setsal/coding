class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        
        // special case 
        if ( len == 0 ) return 0;
        if ( len == 1 ) return cost[1];
        if ( len == 2 ) return min(cost[0], cost[1]);

        vector<int> dp(len+1);
        for ( int i=2; i<len+1; i++ ) {
            dp[i] = min( dp[i-2]+cost[i-2], dp[i-1]+cost[i-1] );
        }
        return dp[len];
    }
};