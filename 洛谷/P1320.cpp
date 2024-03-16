#include <bits/stdc++.h>
using namespace std;
int data[1005], cur = 1;
int main()
{
	char now, last;
	int k = 1, all = 0;
	cin >> last;
	if (last == '1')
		data[cur++] = 0;
	while (cin >> now)
	{
		if (now != last)
		{
			data[cur++] = k;
			k = 1;
		}
		else
		{
			k++;
		}
		last = now;
		all++;
	}
	data[cur] = k;
	cout << ceil(sqrt(all)) << " ";
	for (int i = 1; i <= cur; i++)
	{
		cout << data[i] << " ";
	}
	return 0;
}