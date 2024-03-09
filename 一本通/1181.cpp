#include <bits/stdc++.h>
using namespace std;
int eval[10], ei = 0, oi = 0, odd[10];
void select_sort()
{
	int tempi;
	for (int i = 0; i < ei; i++)
	{
		tempi = i;
		for (int j = i + 1; j < ei; j++)
		{
			if (eval[tempi] > eval[j])
			{
				tempi = j;
			}
		}
		swap(eval[tempi], eval[i]);
	}
}
void select_sort1()
{
	int tempi;
	for (int i = 0; i < oi; i++)
	{
		tempi = i;
		for (int j = i + 1; j < oi; j++)
		{
			if (odd[tempi] < odd[j])
			{
				tempi = j;
			}
		}
		swap(odd[tempi], odd[i]);
	}
}
int main()
{
	int temp;
	for (int i = 0; i < 10; i++)
	{
		cin >> temp;
		if (temp % 2 == 0)
		{
			eval[ei++] = temp;
		}
		else
		{
			odd[oi++] = temp;
		}
	}
	select_sort1();
	select_sort();
	for (int i = 0; i < oi; i++)
		cout << odd[i]<<" ";
	for (int i = 0; i < ei; i++)
		cout << eval[i]<<" ";
	return 0;
}