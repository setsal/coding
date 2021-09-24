// you can use includes, for example:
// #include <algorithm>

#include <bits/stdc++.h>

using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)


    // general
    vector<int> path;
    int relocateCnt = 0;

    int tmpSum = 0;
    for (unsigned int i = 0; i < A.size(); i++) {
        tmpSum += A[i];
        
        path.push_back(A[i]);
        
        if (tmpSum < 0) {
            // find min in previous
            int minElement = *min_element(path.begin(), path.end());
            
            vector<int>::iterator iter = find(A.begin(), A.end(), minElement);  // move to last;
            int minDistance = distance(A.begin(), iter);

            int maxElement = *max_element(A.begin() + minDistance + 1, A.end());
            vector<int>::iterator iter2 = find(A.begin(), A.end(), maxElement);  // move to last;
            int maxDistance = distance(A.begin(), iter2);            

            cout << minElement << endl;
            cout << minDistance << endl;

            // for (int j = A.size() - 1; j > minDistance; j--) {
            //     A[j - 1] = A[j];
            // }
            swap(A[maxDistance], A[minDistance]);
            path.clear();
            tmpSum = 0;
            for (auto item: A) {
                tmpSum += item;
            }

            relocateCnt++;
        }
    }
    // cout << "relocateCnt: " << relocateCnt << endl;
    return relocateCnt;
}
