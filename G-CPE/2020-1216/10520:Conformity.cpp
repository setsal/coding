#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, tmp;
    while (cin >> n && n) {
        map<set<int>,int> myMap;
        for (int i=0; i<n; i++) {
            set<int> mySet;
            for (int j=0; j<5; j++) {
                cin >> tmp;
                mySet.insert(tmp);
            }
            myMap[mySet] += 1;
        }
        int max=-1, ans=0;
        for ( map<set<int>,int>::iterator it = myMap.begin(); it != myMap.end(); ++it ) {
            if ( it->second > max ) max = it->second; // find max frequency
        }
        // poor gpe judge version..
        for ( map<set<int>,int>::iterator it = myMap.begin(); it != myMap.end(); ++it  ) {
            if ( it->second == max ) ans+=max; // count the same frequency times
            // if ( it.second == max ) ans+=max; // count the same frequency times
        }
        cout << ans << endl;
    }

    return 0;
}