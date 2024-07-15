#include <iostream>
#include <algorithm>
using namespace std;
int a[10005];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int *p = unique(a + 1, a + 1 + n);
    int cnt = p - (a + 1);
    if (cnt < k)
    {
        cout << "NO RESULT";
    }
    else
    {
        cout << a[k];
    }
    cout << endl;
    return 0;
}