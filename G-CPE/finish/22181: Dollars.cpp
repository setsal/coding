/*
        Problem: 22181: Dollars
        subs: 648, ACs: 147, AcceptRate: 22.69, onsite: 18, access: 3899

        Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=22181&cid=5
*/

#include <bits/stdc++.h>

using namespace std;

long long coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
long long dp[30005] = {1};

int main() {
    for (int i = 0; i < 11; i++) {
        for (int j = coins[i]; j <= 30000; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    int m1, m2;
    while (scanf("%d.%d", &m1, &m2) != EOF && !(m1 == 0 && m2 == 0)) {
        long long ans = dp[m1 * 100 + m2];
        // cout << ans << endl;
        printf("%3d.%02d%17lld\n", m1, m2, ans);
    }

    return 0;
}