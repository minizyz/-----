#include <bits/stdc++.h>
using namespace std;
char data[9];
char data_raw[9];
bool book[9];
int len;
void print()
{
    for (int i = 0; i < len; i++)
    {
        cout << data[i];
    }
    cout << endl;
    return;
}
void prem(int step)
{
    if (step > len)
    {
        print();
        return;
    }
    for (int i = 1; i <= len; i++)
    {
        if (book[i] == 0)
        {
            data[step] = data_raw[i];
            book[i] = 1;
            prem(step + 1);
            book[i] = 0;
        }
    }
}
int main()
{
    string str;
    cin >> str;
    len = str.size();
    strcpy(data_raw, str.c_str());
    prem(1);
    return 0;
}