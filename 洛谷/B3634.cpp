#include <iostream>
using namespace std;
long long gcd(long long x, long long y)
{
    return (x % y == 0 ? y : gcd(y, x % y));
}
long long lcm(long long x, long long y)
{
    return x * y / gcd(x, y);
}
int main()
{
    long long x, y;
    cin >> x >> y;
    cout << gcd(x, y) << ' ' << lcm(x, y);
}