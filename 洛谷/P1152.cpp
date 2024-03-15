#include <bits/stdc++.h>
using namespace std;
int a[1005];
bool k[1005] = {0};
int main()
{
	//	cout << 1 << endl;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	memset(k, 0, sizeof(k) * sizeof(bool));
	for (int i = 2; i <= n; i++)
	{
		if (abs(a[i] - a[i - 1]) < 1 || abs(a[i] - a[i - 1]) > n - 1)
		{
			cout << "Not jolly";
			return 0;
		}
		else
		{
			if (k[abs(a[i] - a[i - 1])] == 1)
			{
				cout << "Not jolly";
				return 0;
			}
			k[abs(a[i] - a[i - 1])] = 1;
		}
	}
	int j=0;
	for (int i = 1; i < n;i++)
	{
		if (k[i] == 1)
			j++;
	}
	cout << (j + 1 == n ? "Jolly" : "Not jolly");
	return 0;
}