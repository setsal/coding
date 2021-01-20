/*
        Problem: 10679: Irreducible Basic Fractions
        subs: 804, ACs: 120, AcceptRate: 14.93, onsite: 10, access: 3081

        Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=10679&cid=5
*/

#include <bits/stdc++.h>
using namespace std;

int prime[3401] = {2};  //要找5000個質數  質數表
int main(int argc, char *argv[]) {
    int prime_num = 1;
    /* 開始篩選 */
    for (int i = 3; i * i <= 1000000000;
         i += 2)  // 要檢查10e以下有幾個質數 只要檢查到他的開根號
    {
        int judge = 1;
        for (int j = 2; j * j <= i;
             j++)  // 判斷這個數是不是質數 只要檢查到他的開根號
        {
            if (i % j == 0) {
                judge = 0;
            }
        }
        if (judge) {
            prime[prime_num++] = i;
        }
    }
    // cout <<prime_num<<endl; 這邊印出來會是3401 代表小於10億的質數個數
    int input;
    while (cin >> input) {
        int Ans = input;
        if (input) {
            for (int i = 0; i < prime_num && input >= prime[i]; i++) {
                if (input % prime[i] == 0) {
                    while (input % prime[i] == 0) {
                        input /= prime[i];
                    }
                    Ans /= prime[i];
                    Ans *= (prime[i] - 1);
                }
            }
            if (input != 1) {
                Ans /= input;
                Ans *= (input - 1);
            }
        } else {
            break;
        }
        cout << Ans << endl;
    }
    return 0;
}