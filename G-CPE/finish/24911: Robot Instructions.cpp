/*
	Problem: 24911: Robot Instructions
	subs: 2406, ACs: 899, AcceptRate: 37.36, onsite: 12, access: 6131

	Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=24911&cid=5
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, times, postion;
    cin >> n;
    string s, s1;
    int s2;
    while ( n-- ) {
        cin >> times;
        postion = 0;
        string input[1000];
        for ( int i=1; i<=times; i++ ) {
            cin >> s;
            if ( s == "LEFT" ) {
                input[i] = "LEFT";
                postion--;
            }
            else if ( s == "RIGHT" ) {
                input[i] = "RIGHT";
                postion++;
            }
            else {
                cin >> s1 >> s2;
                input[i] = input[s2];
                if ( input[s2] == "RIGHT") postion++;
                else if ( input[s2] == "LEFT" ) postion--;
            }
            // cout << "position:" << postion << endl << endl;
        }
        cout << postion << endl;
    }
    return 0;
}