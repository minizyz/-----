#include <iostream>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <functional>
using namespace std;
bool cmp(int x, int y)
{
    return x < y;
}
int a[100005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 1; i <= n; i++)
    {
        q.push(a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << q.top() << " ";
        q.pop();
    }
    return 0;
}