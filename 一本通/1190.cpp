#include <bits/stdc++.h>
using namespace std;
long long all_n[80] = {0, 1, 2, 4, 7};
int main()
{
	for (int i = 4; i <= 73; i++)
	{
		all_n[i] = all_n[i - 3] + all_n[i - 2] + all_n[i - 1];
	}
	int n;
	cin >> n;
	while (n != 0)
	{
		cout << all_n[n] << endl;
		cin >> n;
	}
	return 0;
}