/*
        Problem: 10417: The Hotel with Infinite Rooms
        subs: 2753, ACs: 817, AcceptRate: 29.68, onsite: 13, access: 7509

        Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=10417&cid=5
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int s;
    long long target_d;
    long long cur_d;
    while (cin >> s >> target_d) {
        cur_d = 1;

        // TLE
        // while (cur_d < target_d) {
        //     dur_s--;
        //     cur_d++;
        //     if (dur_s == 0) {
        //         s++;
        //         dur_s = s;
        //     }
        // }
        // cout << s << endl;
        while (cur_d <= target_d) {
            cur_d += s;
            // cout << " , cur day.." << cur_d << endl;
            s++;
        }
        cout << --s << endl;
    }

    return 0;
}