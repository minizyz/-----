#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int queen[9];
bool x1[20],x2[20],y[30];
int ans = 0;
void QueenPrint()
{
	cout << "No." << (++ans) << endl;
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			cout << (queen[i] == j ? "1" : "_") << ' ';
		}
		cout << endl;
	}
	system("pause&cls");
}
inline bool isOK(int x,int y,int i){
	
}
void Queen(int step)
{
	if (step == 9)
	{
		QueenPrint();
	}
	for (int i = 1; i <= 8; i++)
	{
		if (isOK(step, i))
		{
			
			Queen(step + 1);
		}
	}
}
int main()
{
	for (int i = 1; i <= 8; i++)
	{
		queen[1] = i;
		Queen(2);
	}
	return 0;
}
