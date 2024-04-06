#include <bits/stdc++.h>
using namespace std;
int a[105][105];
char temp;
const int non = 0x80000000;
const int fst = 0;
const int ok = -1;
int fill(char temp, int i, int j)
{
	switch (temp)
	{
	case '#':
	{
		a[i][j] = 0x80000000;
		return 0;
	}
	case '@':
	{
		a[i][j] = 0;
		return 0;
	}
	case '.':
	{
		a[i][j] = -1;
		return 0;
	}
	}
	return -1; // 不会到这
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> temp;
			fill(temp, i, j);
		}
	}
	int m;
	cin >> m;
	for (int day = 1; day <= m; day++)
	{
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (a[i][j] == day || a[i][j] == 0 && day == 1)
				{
					if (a[i][j - 1] == -1)
					{
						//						ans++;
						a[i][j - 1] = day + 1;
					}
					if (a[i - 1][j] == -1)
					{
						//						ans++;
						a[i - 1][j] = day + 1;
					}
					if (a[i][j + 1] == -1)
					{
						//						ans++;
						a[i][j + 1] = day + 1;
					}
					if (a[i + 1][j] == -1)
					{
						//						ans++;
						a[i + 1][j] = day + 1;
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] >= 0)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}