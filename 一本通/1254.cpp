#include <bits/stdc++.h>
using namespace std;
int n, m;
char data[105][105];
bool visited[105][105];
struct pos
{
	int x, y, walk;
};
int dx[10] = {0, 1, -1, 0, 0};//x����ö�� 
int dy[10] = {0, 0, 0, 1, -1};//y����ö�� 
int ans=0;
void bfs(pos start,pos end) // sx,sy:�������;ex,ey:�յ����� 
{
	int ans = 0;
	pos now;
	queue<pos> q; // ���� 
	int curx, cury;//�ĸ������Ӧ��x,yö�� 
	q.push(start);//�����ѹ��ջ�� 
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		visited[now.x][now.y] = 1;
		if (now.x == end.x && now.y == end.y)//���λ����� 
		{
			ans=now.walk;
			return;
		}
		for (int i = 1; i <= 4; i++)
		{
			curx = now.x + dx[i];
			cury = now.y + dy[i];
			if (curx >=1 && cury >= 1 //x,y������ڵ���1 
			 && curx <= n && cury <= m //x,y����С�ڵ���n,m 
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
			if (data[i][j] == 'S') // �ж����λ�� 
			{
				sx = i;
				sy = j;
			}
			if (data[i][j] == 'T') // �ж��յ�λ�� 
			{ 
				ex = i;
				ey = j;
			}
		}
	}
	cout << bfs({sx,sy,0},{ex,ey,0});
	return 0;
}
