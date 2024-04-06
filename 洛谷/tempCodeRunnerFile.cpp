#include <bits/stdc++.h>
using namespace std;
long long data[100005];
bool book[100005];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> data[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		book[i] = 1;
		for (int j = 1; j <= n; j++)
		{
			if (book[j] == 0)
			{
				book[j] = 1;
				for (int k = 1; k <= n; k++)
				{
					if (book[k] == 0)
					{
						book[k] = 1;
						for (int l = 1; l <= n; l++)
						{
							if (book[l] == 0)
							{
								book[l] = 1;
								if (data[i] + data[j] == data[k] && data[k] == data[l])
									ans++;
								else if (data[i] == data[j] + data[k] && data[k] == data[l])
									ans++;
								else if (data[i] == data[j] && data[j] == data[k] + data[l])
									ans++;
								else if (data[k] + data[i] == data[j] && data[k] == data[j])
									ans++;
							}
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}