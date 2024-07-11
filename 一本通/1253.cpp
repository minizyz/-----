#include <bits/stdc++.h>
using namespace std;
struct pos
{
	int x, walk;
};

int bfs(int n, int k)
{
	vector<bool> visited(100001, false); // 添加一个标记数组以避免重复访问同一位置
	queue<pos> q;						 // 修改变量名，避免与queue类名冲突
	q.push({n, 0});
	visited[n] = true; // 标记起始位置已访问

	while (!q.empty())
	{
		pos now = q.front();
		q.pop();
		int nowx = now.x;
		int nowwalk = now.walk;

		if (nowx == k) // 直接在这里返回结果
			return nowwalk;

		// 往左移动
		if (nowx > 0 && !visited[nowx - 1])
		{
			q.push({nowx - 1, nowwalk + 1});
			visited[nowx - 1] = true;
		}
		// 往右移动
		if (nowx < 100000 && !visited[nowx + 1]) // 限制范围防止超出数组
		{
			q.push({nowx + 1, nowwalk + 1});
			visited[nowx + 1] = true;
		}
		// 瞬移
		if (nowx * 2 <= 100000 && !visited[nowx * 2]) // 保证2*nowx不超出范围，并且位置未访问
		{
			q.push({nowx * 2, nowwalk + 1});
			visited[nowx * 2] = true;
		}
	}
	return -1; // 如果找不到，返回-1（理论上不会发生，因为总能通过某种方式到达）
}

int main()
{
	int n, k;
	cin >> n >> k;
	if (n >= k) // 牛的坐标比农夫小或相等，只能一直往左移动或原地不动
		cout << n - k << endl;
	else
	{
		cout << bfs(n, k) << endl;
	}
	return 0;
}