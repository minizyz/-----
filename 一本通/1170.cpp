/*
        程序名：计算2的n次方
*/
#include <bits/stdc++.h>
using namespace std;
class BigInt
{
private:
    int data[1024];
    int len;

public:
    int &operator[](int idx)
    {
        return this->data[idx];
    }
    // 返回数字长度
    int size()
    {
        return len;
    }
    // 更改长度
    int &resize(int n)
    {
        return len = n;
    }
    BigInt()
    {
        memset(data, 0, sizeof(data));
    }
    BigInt(int len) 
    {
        memset(data, 0, sizeof(data));
        this->len = len;
    }
    // 进行展平处理
    int flat()
    {
        for (int i = 1; i <= this->len; i++)
        {
            if (data[i] > 10)
            {
                data[i + 1] = data[i] % 10;
                data[i] /= 10;
                if (i == len)
                {
                    len++;
                }
            }
        }
        while (data[len] == 0 && len > 0)
            len--;
        return len;
    }
    BigInt operator=(BigInt num)
    {
        len = num.size();
        for (int i = 1; i <= num.size(); i++)
        {
            data[i] = num[i];
        }
        return *this;
    }
    BigInt operator*=(BigInt numb)
    {
        int lena = len, lenb = numb.size();
        BigInt numc;
        numc.resize(lena + lenb);
        for (int i = 1; i <= lena; i++)
        {
            for (int j = 1; j <= lenb; j++)
            {
                numc[i + j] += data[i] * numb[j];
            }
        }
        numc.flat();
        (*this) = numc;
        return *this;
    }
    friend ostream &operator<<(ostream &out, BigInt &num)
    {
        for (int i = 1; i <= num.size(); i++)
        {
            out << num[i];
        }
        return out;
    }
};
int main()
{
    int n;
    cin >> n;
    BigInt a;
    BigInt b;
    a.resize(1);
    b.resize(1);
    b[1] = 2;
    a[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        a *= b;
    }
    cout << a;
    return 0;
}