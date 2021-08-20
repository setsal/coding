// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    //dp? not? 或許先拆 
    // A, A.remove()
    // [1, 1, 3, 4, 4, 4]
    // [1,1] [3] [4,4,4]

    // 給每個 block 先判斷達成該 block  最小所需要的情況 ->  重點應該在這塊
    // [1,1] -> cost 1 -> [1]
    // [3] -> cost 1 -> []
    // [4,4,4] -> cost 1 -> []
    
    // 這樣就好了..嗎?  怎麼覺得好像沒這麼單純XD..

    if (A.empty())
        return 0;

    unordered_map<int, int> map;
    for (auto a : A) {
        map[a]++;
    }


    // 可以扣到 0
    // 可以追到 i.first 

    int subToZero;
    int increaseToMax;
    int consume;
    int total = 0;

    for (auto i : map) {
        subToZero = i.second;
        increaseToMax = abs(i.first - i.second);
        consume = subToZero < increaseToMax ? subToZero : increaseToMax;
        // cout << i.first << ", consume: " << consume << endl;
        total += consume;
    }
    return total;
    
    // cout << "---DEBUG---" << endl;
    // // Debug
    // for (auto i : map) {
    //     cout << i.first << " " << i.second << endl;
    // }
}
