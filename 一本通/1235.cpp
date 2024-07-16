#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
long long data[100005]; // 数组
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> data[i];
    }
    int k;
    cin >> k;
    sort(data + 1, data + 1 + n, greater<int>());
    for (int i = 1; i <= k; i++)
        cout << data[i] << endl;
    return 0;
}           