#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <map>

using namespace std;

int main(){
    
    int times;
    int month, day, index;
    
    string week[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    int mondays[12] = {10, 21, 0, 4, 9, 6, 11, 8, 5, 10, 7, 12};
    
    cin >> times;

    for (int i=0; i<times; i++) {    
        cin >> month >> day;
        int curMonDay = mondays[--month];
        index = (day-curMonDay) % 7;
        if ( index >= 0 ) {
            cout << week[index] << endl;    
        }
        else {
            cout << week[7 + index] << endl;
        }
    }
    return 0;
}