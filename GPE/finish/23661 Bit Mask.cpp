/*
        Problem: 23661: Bit Mask
        subs: 392, ACs: 101, AcceptRate: 25.77, onsite: 8, access: 2605

        Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=23661&cid=5
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned int N, L, U, ans;
    // cout << (1u << 1) << endl;
    // cout << (1u << 2) << endl;
    // return 0;
    while (cin >> N >> L >> U) {
        ans = 0;
        // shift greedy
        for (int i = 31; i >= 0; i--) {
            unsigned int shift = 1 << i;
            // cout << "i:" << i << ",shift:" << shift;
            if ((ans | shift) > U) {
                // cout << ", ans|shift:" << (ans | shift) << endl;
                continue;
            }
            // cout << ", ans|shift:" << (ans | shift) << ", N&shift:"
            //      << (N & shift);  // N & shift 表示該 bits AND 結果, 若 0 ->
            //                       // 進入將他 OR 變成 1
            if ((ans | shift) <= L || !(N & shift)) {
                ans = ans | shift;
                // cout << ", ans:" << ans << endl;
            }
        }
        cout << ans << endl;
    }

    return 0;
}