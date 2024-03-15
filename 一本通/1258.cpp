#include <bits/stdc++.h>
using namespace std;
int t[1005][1005];
int main()
{
    int R;
    cin >> R;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> t[i][j];
        }
    }
    for (int i = R - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            t[i][j] += max(t[i + 1][j], t[i + 1][j + 1]);
        }
    }
    cout << t[1][1];
    return 0;
}