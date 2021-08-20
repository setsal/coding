#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



using namespace std;
/*
 * Complete the 'plusMult' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY A as parameter.
 */

string plusMult(vector<int> A) {
    
    int rEvenSum = 0;
    int rOddSum = 0;
    int index = 0, val = 0;
    bool multiflag = false;

    for (auto a : A) {                
        if (index % 2 == 0) {
            if (multiflag == true) {
                rEvenSum = (rEvenSum % 2 == 0 || a % 2 == 0) ? 2 : 3;    
            }
            else {
                if (rEvenSum % 2 == 0 && a % 2 == 0) {
                    rEvenSum = 2;
                }
                else if ( rEvenSum % 2 == 1 && a % 2 == 1) {
                    rEvenSum = 2;
                }
                else {
                    rEvenSum = 3;
                }
            }
        }
        else {
            if (multiflag == 1) {
                rOddSum = (rOddSum % 2 == 0 || a % 2 == 0) ? 2 : 3;
                multiflag = false;    
            }
            else {
                if (rOddSum % 2 == 0 && a % 2 == 0) {
                    rOddSum = 2;
                }
                else if ( rOddSum % 2 == 1 && a % 2 == 1) {
                    rOddSum = 2;
                }
                else {
                    rOddSum = 3;
                }                
                multiflag = true;
            }
        }
        index++;
    }
    
    int rEven = rEvenSum % 2;
    int rOdd = rOddSum % 2;
    string res;
    
    if (rOdd > rEven){
        res = "ODD";
    }
    else if (rOdd == rEven) {
        res = "NEUTRAL";
    }
    else {
        res = "EVEN";
    }
    
    return res;
}

int main()