/*
	Problem: 11017: Longest Common Subsequence
	subs: 1262, ACs: 245, AcceptRate: 19.41, onsite: 12, access: 3724

	Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=11017&cid=5
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    int l1, l2;
    int dp[1005][1005];
    while ( cin >> s1 >> s2 ) {
        l1 = (int)s1.length();
        l2 = (int)s2.length();
        dp[1005][1005] = {0};
        memset(dp, 0, sizeof(dp));
        for ( int i=1; i<=l1; i++ ) {
            for ( int j=1; j<=l2; j++ ) {
                if ( s1[i-1] == s2[j-1] ) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        cout << dp[l1][l2] << endl;

    }
    return 0;
}