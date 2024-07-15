#include <iostream>
#include <string>
using namespace std;
void hanoi(int n, string a, string b, string c)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        hanoi(n - 1, a, b, c);
        cout<<a<<"->"<<
    }
}
int main()
{
    int n;
    cin >> n;
    hanoi(n, "a", "b", "c");
    return 0;
}