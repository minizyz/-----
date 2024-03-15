#include <bits/stdc++.h>
using namespace std;
struct student
{
    int id;
    int chinese;
    int all;
} students[305];

int main()
{
    int n;
    cin >> n;
    int math, english;
    for (int i = 1; i <= n; i++)
    {
        cin >> students[i].chinese >> math >> english;
        students[i].id = i;
        students[i].all = students[i].chinese + math + english;
    }
    return 0;
}