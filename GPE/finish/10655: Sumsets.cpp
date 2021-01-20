/*
        Problem: 10655: Sumsets
        subs: 2479, ACs: 333, AcceptRate: 13.43, onsite: 16, access: 8932

        Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=10655&cid=5
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> dict;

int main() {
    int n, input;
    bool found;
    while (cin >> n && n != 0) {
        // set<int> nums;
        vector<int> nums;
        found = false;

        for (int i = 0; i < n; i++) {
            cin >> input;
            nums.push_back(input);  // auto sort
        }

        sort(nums.begin(), nums.end(), greater<int>());

        for (int d = 0; d < nums.size() && !found; d++) {
            for (int b = 0; b < nums.size() && !found; b++) {
                for (int c = b + 1; c < nums.size() && !found; c++) {
                    int a = nums[d] - nums[b] - nums[c];
                    if (d == b || d == c) continue;
                    if (a == nums[d] || a == nums[b] || a == nums[c]) continue;
                    if (count(nums.begin(), nums.end(), a)) {
                        cout << nums[d] << endl;
                        found = true;
                    }
                }
            }
        }

        // for (set<int>::reverse_iterator it_d = nums.rbegin();
        //      it_d != nums.rend() && !found; it_d++) {
        //     for (set<int>::reverse_iterator it_b = nums.rbegin();
        //          it_b != nums.rend() && !found; it_b++) {
        //         for (set<int>::reverse_iterator it_c = it_b, ;
        //              it_c != nums.rend(); it_c++) {
        //             int a = *it_d - *it_b - *it_c;
        //             if (it_d == it_b || it_d == it_c) continue;
        //             if (a == *it_d || a == *it_b || a == *it_c) continue;
        //             if (nums.count(a)) {
        //                 cout << *it_d << endl;
        //                 found = true;
        //             }
        //         }
        //     }
        // }
        if (!found) cout << "no solution" << endl;
    }

    return 0;
}