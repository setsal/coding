// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    // ..感覺會有沒考慮到的耶...  也不太像是 two sum...嗎  dp?  質因數分解?  I stuck..
    // Give up XD

    int sum = 0;
    map<int, int> map;

    for (auto a : A) {
        sum += a;
        if (a > 1000000000)
            return - 1;
        
        // increase map value
        map[a]++;
    }

    // single or zero case
    if ( map.size() == 1 || sum != 0)
        return -1;
    
    vector<int> tmpArray;

    for (auto it = A.begin(); it != A.end(); it++) {
        tmpArray.assign(A.begin(), A.end());
        auto it2 = ++tmpArray.begin();
        for (; it2 != tmpArray2.end(); it++) {
            if ()
        }
    }
    

    // // Debug
    // for (auto i : map) {
    //     cout << i.first << " " << i.second << endl;
    // }

    // cout << "--after--" << endl;

    // for (auto i : map) {
    //     if (i.first < 0) {
    //         map[abs(i.first)]--;
    //     }
    //     cout << i.first << " " << i.second << endl;
    // }


    return -1;
}
