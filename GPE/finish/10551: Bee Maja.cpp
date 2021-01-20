#include <bits/stdc++.h>

using namespace std;

int main()
{
	int pre[200];
	pre[0] = 1;

	for (int i = 0; pre[i] <= 100000; i++)
	{
		pre[i + 1] = pre[i] + (i + 1) * 6;
	}

	int n;
	bool neg;
	while (cin >> n)
	{
		if (n == 1)
		{
			cout << "0 0" << endl;
			continue;
		}

		int cir = 0;
		// for (cir = 1; pre[cir] < n; cir++)
		//     ;
		// int cir2;
		for (int i = 1; i < 200; i++)
		{
			// cout << pre[i] << endl;
			if (pre[i] >= n)
			{
				cir = i;
				break;
			}
		}

		// cout << "cir:" << cir << ",cir2:" << cir2 << endl;
		// continue;

		int cir_start;
		cir_start = pre[cir - 1] + 1;
		// cout << "cir:" << cir << endl;

		// 應應對稱 推算半圈來決定變換數字  cir*3 是計算半圈的蜂巢個數 e.g 6->3, 12->6
		if (n - cir_start >= cir * 3) // 17 - 8 >= 2*3
		{
			neg = true;
			n = n - cir * 3; // n 17 -> 11  去掉半圈以後的數量只推算一邊 然後計算要走的數量
		}
		else
		{
			neg = false;
		}

		// start position (0, 1) (1, 1) (2, 1) 每個圈一開始的位置
		int x = cir - 1;
		int y = 1;

		// cout << "start pos:" << x << " " << y << endl;
		int cnt = n - cir_start; // cnt = 11 - 8 = 3  計算總共需要走得步數
		int tmp = cir - 1;		 // tmp = 1  需要往左下幾次才會走到邊？ （ 往左下 -1, +1 )

		// cout << "cnt:" << cnt << endl;
		// cout << "tmp:" << tmp << endl;

		while (cnt && tmp) // 計算左下 ( -1, 1 )
		{
			x -= 1;
			y += 1;
			cnt--;
			tmp--;
		}
		// cout << "pos:" << x << " " << y << endl; // 來到該圈最下面

		tmp = cir;
		while (cnt && tmp) // 計算往左上 ( -1, 0 ) 即可 第二圈來講, 撇除第一個點需要 2,  第三圈來講, 撇除第一個點需要 3
		{
			x -= 1;
			--cnt;
			--tmp;
		}
		// cout << "pos:" << x << " " << y << endl;

		tmp = cir;
		while (cnt && tmp) // 計算往上 ( 0, -1 ) 的數量
		{
			y -= 1;
			--cnt;
			--tmp;
		}
		// cout << "pos:" << x << " " << y << endl;

		if (neg)
		{
			x = -x;
			y = -y;
		}

		cout << x << " " << y << endl;
	}
	return 0;
}