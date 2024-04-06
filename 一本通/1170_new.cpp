#include <bits/stdc++.h>
using namespace std;
int a[2048];
int main()
{
    memset(a, 0, sizeof(a));
    int n, x;
    cin >> n;
    int len = 1;
    a[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        x = 0;
        for (int j = 1; j <= len; j++)
        {
            a[j] = a[j] * 2 + x;
            x = a[j] / 10;
            a[j] %= 10;
            if (x != 0 && j == len)
            {
                len++;
            }
            //            cout << len << endl;
        }
    }
    for (int i = len; i >= 1; i--)
    {
        cout << a[i];
    }
    return 0;
}