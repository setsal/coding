/*
        Problem: 22151: Big Mod
        subs: 2083, ACs: 279, AcceptRate: 13.39, onsite: 18, access: 3932

        Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=22151&cid=5
*/

#include <bits/stdc++.h>
using namespace std;

long long int mod(long long int B, long long int P, long long int M) {
    if (P == 0)
        return 1;

    else if (P == 1)
        return B % M;

    else

    {
        if (P % 2 == 0)
            return mod(B, P / 2, M) * mod(B, P / 2, M) % M;

        else
            return mod(B, P - 1, M) * (B % M) % M;
    }
}

using namespace std;

int main()

{
    long long int B, P, M, R;

    while (cin >> B >> P >> M)

    {
        cout << mod(B, P, M) << endl;
    }

    return 0;
}
