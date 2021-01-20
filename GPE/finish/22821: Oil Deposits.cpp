/*
	Problem: 22821: Oil Deposits
	subs: 1812, ACs: 489, AcceptRate: 26.99, onsite: 16, access: 5475

	Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=22821&cid=5
*/

#include <bits/stdc++.h>
using namespace std;

bool oil[101][101];

void dfs(int indexi, int indexj){
    for ( int i = -1; i<=1; i++ ) {
        for ( int j=-1; j<=1; j++ ) {
            if ( indexi+i < 0 || indexj + j < 0 ) 
                continue;
            if (oil[indexi+i][indexj+j]) {
                oil[indexi+i][indexj+j] = false;
                dfs(indexi+i, indexj+j);
            }
        }
    }
}

int main () {
    int m, n;
    char input;
    while ( cin >> m >> n && m && n ) {
        // reset;
        oil[101][101] = { false };
        
        for ( int i=0; i<m; i++ ) {
            for ( int j=0; j<n; j++ ) {
                cin >> input;
                if ( input == '@') oil[i][j] = true;
            }
        }
        int cnt = 0;
        for ( int i=0; i<m; i++ ) {
            for ( int j=0; j<n; j++ ) {
                if ( oil[i][j] == true ) {
                    cnt++;
                    oil[i][j] = false;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}