#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



using namespace std;

/*
 * Complete the 'maxPresentations' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY scheduleStart
 *  2. INTEGER_ARRAY scheduleEnd
 */

int maxPresentations(vector<int> scheduleStart, vector<int> scheduleEnd) {
    int length = scheduleStart.size();
    int res = 0;
    
    vector<pair<int, int>> myVect;
    for (int i = 0; i < length; i++){
        myVect.push_back(make_pair(scheduleStart[i], scheduleEnd[i]));
    }
    
    sort(myVect.begin(), myVect.end());
    
    for (int i = 0; i < length; i++) {
        cout << myVect[i].first << " " << myVect[i].second << endl;
    }
    
    cout << "length: " << length << endl;
    // Greedy Sol
    
    // End loop
    for (int i = 0; i < length; i++) {   
        
        int curScheduleEnd = myVect[i].second;
        int curMax = 1;
        
        // start loop
        for (int j = 0; j < length; j++) {
            if (j == i)  {
                continue;
            }
                
            // e.g. match
            if(myVect[j].first >= curScheduleEnd) {
                curScheduleEnd = myVect[j].second;
                curMax++;
            } 
        }
        if (curMax > res) {
            res = curMax;
        }
        
    }
    
    return res;
    // map<int, int> myMap;
    
    // for(int i = 0; i < length; i++) {
    //     myMap[scheduleStart[i]]++;
    //     myMap[scheduleEnd[i]]--;
    // }
}

int main()