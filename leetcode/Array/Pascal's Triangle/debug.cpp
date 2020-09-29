#include <iostream>
#include <vector>
using namespace std;

void generate(int numRows) {
        
        // initial
        vector<int> cur;
        
        vector<vector<int>> res;

        if ( numRows == 0 ) return vector<vector<int>>();

        // first element
        cur.push_back(1);
        res.push_back(cur);
        if ( numRows == 1 ) return res;

        // second element
        cur.push_back(1);
        res.push_back(cur);
        if ( numRows == 2 ) return res;

        int tmp;

        // third to last
        for(int i=1; i<=numRows-2; i++) {
            cur.insert(cur.begin()+1, cur[1]);
            for ( int j=0; j<i; j++ ) {
                tmp = cur[j+1];
                if ( j==0 ) {
                    cur[j+1] = cur[j]+cur[j+2];
                }
                else {
                    cur[j+1] = tmp+cur[j+2];
                }
            }
            res.push_back(cur);
        }

        for (int i=0; i<res.size(); i++ ) {
            for ( int j=0; j<res[i].size(); j++ ) {
                cout << res[i][j] << ' ';
            }
            cout << endl;
        }
}

int main() {
    generate(8);
    return 0;
}