/*
        Problem: 11041: Children's Game
        subs: 2351, ACs: 435, AcceptRate: 18.5, onsite: 19, access: 6520

        Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=11041&cid=5
*/

#include <bits/stdc++.h>

using namespace std;

string word[51];

int cmp(string s1, string s2) { return (s1 + s2) > (s2 + s1); }

int main() {
    int n;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> word[i];
        }
        sort(word, word + n, cmp);
        // for (auto w : word) cout << w;
        for (int i = 0; i < n; i++) cout << word[i];
        cout << endl;
    }
}