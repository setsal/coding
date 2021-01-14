/*
	Problem: 10579: Hay Points
	subs: 647, ACs: 367, AcceptRate: 56.72, onsite: 15, access: 3224

	Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=10579&cid=5
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	map<string, int> myMap;

	string word;
	int value;
	for (int i = 0; i < m; i++)
	{
		cin >> word >> value;
		myMap[word] = value;
	}

	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		while (cin >> word && word != ".")
		{
			if (myMap[word] > 0)
				sum += myMap[word];
		}
		cout << sum << endl;
	}

	return 0;
}