#include <bits/stdc++.h>
using namespace std;
int *a;
// #define LOCAL
int main()
{
	int n, m;
	cin >> n >> m;
	a = new int[n + 5]; // 由于原题数据范围未知，所以开动态数组
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int num = 0, // 有多少位同学完成了接水
		idx = m, // 下一位顶上去的同学是谁
		ans = 0; // 累计接水使用的时间
	while (num < n)
	{
		for (int i = 0; i < m; i++) // 读取这m位同学
		{
			a[i]--; // 同学i接了一单位水
			if (a[i] == 0)
			{
				if (idx < n) // 如果还有学生可以顶上去（否则会“凭空”冒出学生）
				{
					a[i] = a[idx]; // 那么就让他顶上去
				}
				idx++; // 指向下一个可以顶上去的学生
				num++; // 多了一个打完水的同学
			}
		}
		ans++; // 接水多用了1秒时间
	}
	cout << ans;
	return 0;
}