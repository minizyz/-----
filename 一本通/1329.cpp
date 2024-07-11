#include <bits/stdc++.h>
#include<cstring>
using namespace std;
int m, n;
int ans = 0;
int a[105][105];
bool vis[105][105];
typedef int X;
typedef int Y;
typedef struct
{
    int x, y;
} node;
int dx[5] = {0, 1, -1, 0, 0},
    dy[5] = {0, 0, 0, -1, 1};
bool check(int x, int y)
{
    if (x >= 1 && x <= m && y >= 1 && y <= n && vis[x][y] == 0 && a[x][y] != 0)
    {
        return true;
    }
    return false;
}
void bfs(int x, int y)
{
    queue<node> q;
    q.push({x, y});
    vis[x][y] = 1;
    a[x][y] = 0;
    while (!q.empty())
    {
        node t = q.front();
        q.pop();
        for (int i = 1; i <= 4; i++)
        {
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if (check(nx, ny))
            {
                vis[nx][ny] = 1;
                a[nx][ny] = 0;
                q.push({nx, ny});
            }
        }
    }
}
int main()
{
	memset(a,0,sizeof(a));	
	memset(vis,0,sizeof(vis));
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
            if (a[i][j] != 0 && vis[i][j] == 0)
            {
                bfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
