/*
	Problem: 10471: COUNTING CHAOS
	subs: 463, ACs: 112, AcceptRate: 24.19, onsite: 10, access: 2119

	Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=10471&cid=5
*/

#include <bits/stdc++.h>
using namespace std;

void addOne(string& s) {
    s[3] += 1;
    if ( s[3] > '9' ) {
        s[3] = '0';
        s[2] += 1;
        if ( s[2] == '6' ) {
            s[2] = '0';
            s[1] += 1;

            if ( s[1] > '9' || (s[0] == '2' && s[1] == '4') ) {
                s[1] = '0';
                s[0] +=1;
                if ( s[0] == '3' ) {
                    s[0] = '0';
                }
            }
        }
    }
}


bool isTrue(string s)
{
    int start =0, end=3;
    while ( s[start] == '0' )
        start++;

    while ( start < end ) {
        if ( s[start] != s[end] ) 
            return false;
        start++;
        end--;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        s.erase(2,1);
        addOne(s);
        while (!isTrue(s)) {
            addOne(s);
        }
        cout << s[0] << s[1] << ":" << s[2] << s[3] << endl;
    }

    return 0;
}

// 3
// 00:00
// 23:30
// 14:59