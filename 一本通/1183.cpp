#include <bits/stdc++.h>
using namespace std;
struct people
{
    int q;
    char id[10];
    int year;
} data[105];
bool IsOlds(people a)
{
    return a.year >= 60;
}
bool cmp(people a, people b)
{
    if (IsOlds(a) && !IsOlds(b))
    {
        return true;
    }
    else if (!IsOlds(a) && IsOlds(b))
    {
        return false;
    }
    else if (IsOlds(a) && IsOlds(b))
    {
        if (a.year == b.year)
        {
            return a.q < b.q;
        }
        return a.year > b.year;
    }
    return a.q < b.q;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> data[i].id >> data[i].year;
        data[i].q = i;
    }
    sort(data + 1, data + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << data[i].id << endl;
    }
    return 0;
}