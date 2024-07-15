#include <iostream>
#include <algorithm>
using namespace std;
int family[100005];
int find(int i)
{
    if (family[i] == i)
        return i;
    else
        return family[i] = find(family[i]);
}
int main()
{
    int n, m;
    cin >> n >> m;
    char com;
    for (int i = 1; i <= n; i++)
        family[i] = i;
    for (int i = 1; i <= m; i++)
    {
        cin >> com;
        switch (com)
        {
        case 'M':
        {
            int a, b;
            cin >> a >> b;
            family[a] = find(b);
            break;
        }
        case 'Q':
        {
            int a;
            cin >> a;
            int ans = count_if(family + 1, family + 1 + n, [&a](int x) -> bool{ return x == family[a]; });
            cout << ans << endl;
            break;
        }
        default:
            break;
        }
    }
}
