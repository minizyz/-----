#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;
int mx = 0, fmx = 0;
double male[40], female[40];
bool comp(double x, double y)
{
	return x > y;
}
int main()
{
	int n;
	cin >> n;
	string ism;
	double tall;
	for (int i = 1; i <= n; i++)
	{
		cin >> ism >> tall;
		if (ism == "male")
			male[++mx] = tall;
		else
			female[++fmx] = tall;
	}
	stable_sort(male + 1, male + 1 + mx);
	stable_sort(female + 1, female + fmx + 1, comp);
	cout.precision(2);
	for (int i = 1; i <= mx; i++)
		cout << fixed << male[i] << " ";
	for (int i = 1; i <= fmx; i++)
		cout << fixed << female[i] << " ";
	return 0;
}
