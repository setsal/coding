/*
	Problem: 21944: Power Crisis
	subs: 1950, ACs: 445, AcceptRate: 22.82, onsite: 27, access: 7121

	Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=21944&cid=5
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while (cin >> n && n)
	{
		for (int i = 1; i < n; i++)
		{
			int k = 0;
			for (int j = 1; j < n; j++)
			{
				k = (k + i) % j;
			}
			if (k == 11)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}