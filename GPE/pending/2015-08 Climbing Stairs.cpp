/*
        Problem: 2015-08: Climbing Stairs
        subs: 2421, ACs: 142, AcceptRate: 5.87, onsite: 7, access: 5153

        Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=2015-08&cid=5
*/

#include <bits/stdc++.h>

using namespace std;

long long dp[150];

// int loop(int n) {
//     if (n == 1) return 1;
//     if (n == 2) return 2;
//     if (dp[n]) return dp[n];
//     return dp[n] = loop(n - 1) + loop(n - 2);
// }

int getAns(int n) {
    double a1 = 1 / sqrt(5);
    double a2 = pow((1 + sqrt(5)) / 2, n + 1);
    double a3 = pow((1 - sqrt(5)) / 2, n + 1);
    int ans = (int)(a1 * (a2 - a3));
    return ans;
}

int main() {
    int n;

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < 101; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    while (cin >> n) {
        // memset(dp, 0, sizeof(dp));
        // int ans = loop(n);
        long long ans = dp[n];
        // int ans = getAns(n);
        cout << ans << endl;
    }

    return 0;
}