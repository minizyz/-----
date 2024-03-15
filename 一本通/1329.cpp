#include <iostream>
#include <utility>
#include <queue>
using namespace std;
int data[3000][3000], ans = 0;
typedef pair<int, int> pos;
void bfs(int x, int y, int n, int m)
{
	queue<pos> q;
	q.push(pos(x, y));
	while (!(q.empty()))
	{
		int nowx = q.front().first, nowy = q.front().second;
		q.pop();
		data[nowx][nowy] = 0;
		if (data[nowx][nowy + 1])
		{
			q.push(pos(nowx, nowy + 1));
		}
		if (data[nowx][nowy - 1])
		{
			q.push(pos(nowx, nowy + 1));
		}
		if (data[nowx + 1][nowy])
		{
			q.push(pos(nowx, nowy + 1));
		}
		if (data[nowx - 1][nowy])
		{
			q.push(pos(nowx, nowy + 1));
		}
	}
	ans++;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			data[i][j] = cin.get() - '0';
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (data[i][j])
			{
				bfs(i, j, n, m);
			}
		}
	}
	cout << ans;
	return 0;
}