/*
        Problem: 24941: Uncompress
        subs: 439, ACs: 140, AcceptRate: 31.89, onsite: 20, access: 3345

        Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=24941&cid=5
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> dict;

// void printDict() {
//     for (auto i : dict) {
//         cout << i << " ";
//     }
//     cout << endl;
// }

int main() {
    string s;
    int value;

    while (getline(cin, s) && s != "0") {
        string tmp;
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                tmp = "";
                while (isalpha(s[i])) {
                    tmp.insert(tmp.end(), s[i]);
                    i++;
                }
                dict.push_back(tmp);
                i--;
                cout << tmp;
            } else if (isdigit(s[i])) {
                value = 0;
                while (isdigit(s[i])) {
                    value = value * 10 + (s[i] - '0');
                    i++;
                }
                tmp = dict[dict.size() - value];
                dict.erase(dict.end() - value);
                dict.push_back(tmp);

                i--;
                cout << tmp;
            } else {
                cout << s[i];
            }
        }
        cout << endl;
    }

    return 0;
}