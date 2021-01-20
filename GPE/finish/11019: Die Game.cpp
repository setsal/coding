/*
	Problem: 11019: Die Game
	subs: 3222, ACs: 1046, AcceptRate: 32.46, onsite: 15, access: 12653

	Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=11019&cid=5
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while (cin >> n && n) {
        string s;

        // up, down, east, south, west, north
        // int faces[6] = { 1, 6, 4, 5, 4, 2 };
        int D = 6;
        int E = 4, W = 3, S=5, N=2;
        int curChange = 1;

        for ( int i=0; i<n; i++) {
            cin >> s;
            if ( s == "north" ) {
                N = curChange;
                curChange = S;
                S = 7 - N;
                D = 7 - curChange;
            }
            else if ( s == "east") {
                E = curChange;
                curChange = W;
                W = 7 - E;
                D = 7 - curChange;
            }
            else if ( s == "south") {
                S = curChange;
                curChange = N;
                N = 7 - S;
                D = 7 - curChange;
            }
            else if ( s == "west" ) {
                W = curChange;
                curChange = E;
                E = 7 - W;
                D = 7 - curChange;
            }
        }
        cout << curChange << endl;
    }

    return 0;
}