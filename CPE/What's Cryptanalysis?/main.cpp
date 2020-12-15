#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <map>

using namespace std;

int main() {
    int times;
    char m[100] = {0};
    string s;
    cin >> times >> ws;
    while (times--) {
        getline(cin, s);
        for (int i=0; i<s.length(); i++) {
            if (isalpha(s[i])) {
                m[toupper(s[i])]++;
            }
        }
    }
    for (int i=99; i>0; i--) {
        for ( int j=65; j<=91; j++) {
            if(m[j] == i) {
                cout << char(j) << " " << i << endl;
            }
        }
    }
    return 0;
}