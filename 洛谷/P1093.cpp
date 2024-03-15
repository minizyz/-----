#include <bits/stdc++.h>
using namespace std;
struct student
{
    int id;
    int chinese;
    int all;
} students[305];
bool compare(const student &a, const student &b)
{
    if(a.all==b.all){
        if(a.chinese==b.chinese){
            return a.id<b.id;
        }
        else{
            return a.chinese>b.chinese;
        }
    }
    else{
        return a.all>b.all;
    }
}
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
    sort(students+1,students+n+1,compare);
    return 0;
}