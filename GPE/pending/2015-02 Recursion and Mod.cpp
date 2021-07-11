/*
        Problem: 2015-02: Recursion and Mod
        subs: 1763, ACs: 179, AcceptRate: 10.15, onsite: 8, access: 3445

        Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=2015-02&cid=5
*/

#include <stdio.h>
#include <stdlib.h>
long long cal(int a, long long n, long long b) {
    if (n == 1)
        return 3;
    else {
        long long result = cal(a, n / 2, b);
        if (n % 2 == 1) {
            return ((result * result * 3)) % b;
        } else {
            return ((result * result)) % b;
        }
    }
}
int main() {
    long long n;
    while (scanf("%lld", &n) != EOF) {
        n = cal(3, n, 1000000009);
        printf("%lld\n", n - 2);  //可以透過觀察得知 i th ans = 3 的 i 次方 -2
    }
}