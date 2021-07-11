/*
        Problem: 21944: Power Crisis
        subs: 1950, ACs: 445, AcceptRate: 22.82, onsite: 27, access: 7121

        Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=21944&cid=5
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, token;
    int ans;

    while (cin >> s && s != ".") {
        cout << s << endl;
        stringstream sin(s);
        while (sin >> token) cout << token << endl;
    }

    return 0;
}