#include <bits/stdc++.h>
using namespace std;
int n, m;
char data[105][105];
bool visited[105][105];
struct pos
{
	int x, y, walk;
};
int dx[10] = {0, 1, -1, 0, 0};//x方向枚举 
int dy[10] = {0, 0, 0, 1, -1};//y方向枚举 
int ans=0;
void bfs(pos start,pos end) // sx,sy:起点坐标;ex,ey:终点坐标 
{
	int ans = 0;
	pos now;
	queue<pos> q; // 队列 
	int curx, cury;//四个方向对应的x,y枚举 
	q.push(start);//将起点压入栈中 
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		visited[now.x][now.y] = 1;
		if (now.x == end.x && now.y == end.y)//如果位于起点 
		{
			ans=now.walk;
			return;
		}
		for (int i = 1; i <= 4; i++)
		{
			curx = now.x + dx[i];
			cury = now.y + dy[i];
			if (curx >=1 && cury >= 1 //x,y坐标大于等于1 
			 && curx <= n && cury <= m //x,y坐标小于等于n,m 
			 && (data[curx][cury] == '.' || data[curx][cury] == 'T') 
			 && !visited[curx][cury])
			{
				q.push({curx, cury, now.walk + 1});
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	int sx, sy, ex, ey;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> data[i][j];
			if (data[i][j] == 'S') // 判断起点位置 
			{
				sx = i;
				sy = j;
			}
			if (data[i][j] == 'T') // 判断终点位置 
			{ 
				ex = i;
				ey = j;
			}
		}
	}
	cout << bfs({sx,sy,0},{ex,ey,0});
	return 0;
}
