#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = 0, temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        ans ^= temp; // 内存只有4MB，要用位运算技巧
    }
    cout << ans;
}