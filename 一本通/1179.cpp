#include <bits/stdc++.h>
using namespace std;
struct stu
{
    int id;
    int score;
    int chinese;
} student[305];
bool comp(const stu a, const stu b)
{
    if (a.score == b.score)
    {
        if (a.chinese == b.chinese)
        {
            return a.id < b.id;
        }
        return a.chinese > b.chinese;
    }
    return a.score > b.score;
}
int main()
{
    int n, math, english;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> student[i].chinese >> math >> english;
        student[i].score = student[i].chinese + math + english;
        student[i].id = i;
    }
    sort(student + 1, student + 1 + n, comp);
    for (int i = 1; i <= 5; i++)
    {
        cout << student[i].id << " " << student[i].score << endl;
    }
    return 0;
}