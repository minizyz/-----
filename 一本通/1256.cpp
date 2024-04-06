#include <iostream>
#include <queue>
#include <utility>
using namespace std;
bool dat[205][205];
char read;
int startx, starty, endx, endy;
typedef __pos;
typedef class pos
{
private:
public:
	pair<int, int> postions;
	int walk;
	pos(int x, int y, int walk);
	~pos();
} pos;

pos::pos(int x, int y, int walk)
{
	this->postions = __pos(x, y);
	this->walk = walk;
}

pos::~pos()
{
}

int bfs(int R, int C)
{
	queue<pos> q;
	q.push(pos(startx, starty, 0));
	while (!q.empty())
	{
		pos now = q.front();
		q.pop();
		int nowx = now.postions.first;
		int nowy = now.postions.second;
		int walk = now.walk;
		if (nowx == endx && nowy == endy)
		{
			return walk;
		}
		else
		{
			if (dat[nowx][nowy + 1] == 0)
			{
				q.push(pos(nowx, nowy + 1, walk + 1));
			}
			if (dat[nowx + 1][nowy] == 0)
			{
				q.push(pos(nowx + 1, nowy, walk + 1));
			}
			if (dat[nowx][nowy - 1] == 0)
			{
				q.push(pos(nowx, nowy - 1, walk + 1));
			}
			if (dat[nowx - 1][nowy] == 0)
			{
				q.push(pos(nowx - 1, nowy, walk + 1));
			}
		}
	}
	return -1;
}
int main()
{
	int T, R, C;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> R >> C;
		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				cin >> read;
				if (read == '#')
				{
					dat[i][j] = 1;
				}
				else
				{
					dat[i][j] == 0;
					if (read == 'S')
					{
						startx = i;
						starty = j;
					}
					if (read == 'S')
					{
						endx = i;
						endy = j;
					}
				}
			}
		}
		int ans = bfs(R, C);
		if (ans == -1)
		{
			cout << "oop!";
		}
		else
		{
			cout << ans;
		}
		cout << endl;
	}
}
