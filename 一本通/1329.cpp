#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int m, n;
int ans = 0;
int a[105][105];
typedef int X;
typedef int Y;
typedef struct
{
	int x, y;
} node;
int dx[5] = {0, 1, -1, 0, 0},
	dy[5] = {0, 0, 0, -1, 1};
void bfs(int x, int y)
{
	queue<node> q;
	q.push({x, y});
	while (!q.empty())
	{
	}
}
int main()
{
	cin >> n >> m;
	string data;
	getline(cin, data);
	for (int i = 1; i <= n; i++)
	{
		getline(cin, data);
		for (int j = 0; j < m; j++)
		{
			a[i][j + 1] = data[j] - '0';
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] != 0)
			{
				bfs(i, j);
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
