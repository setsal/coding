#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int getCount(int value) {
        int count = 0;
        while( value != 0 ) {
            value = value/10;
            count++;
        }
        return count;
    }
    
    bool isPalindrome(int x) {
        int count = getCount(x);
        int i;
        if ( x == 0 || (x >=0 && x%10 != 0) ) {
            for ( i=1; i<=count/2; i++ ) {
                if ( x/int(pow(10, count-i))%10 == x/int(pow(10, i-1))%10) {
                    continue;
                } else {
                    return false;
                }
            }
            return true;
        } else {
            return false;  
        }
    }
};

int main() {
    Solution sol;
    cout << (sol.isPalindrome(121) ? "true" : "false")  << endl;
    return 0;
}