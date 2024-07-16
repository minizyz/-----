#include <iostream>
#include <iomanip>
using namespace std;
bool cos[10], a[30], b[30];
bool queens[15][15];
int ans = 0;
void Print()//打印 
{
	++ans;
	cout << "No. " << ans << endl;
	for (int j = 1; j <= 8; j++)
	{
		for (int i = 1; i <= 8; i++)
		{
			cout << (queens[i][j] ? '1' : '0') << ' ';//如果对应项是true,那么对应输出1，否则输出0 
		}
		cout << endl;
	}
}
void Queen(int i)
{
	if(i>8){
		Print();
		return;
	}
	for(int j=1;j<=8;j++){
		if(!cos[j]&&!a[i-j+7]&&!b[i+j]){
			queens[i][j]=true;//标记势力 
			cos[j]=true;
			a[i-j+7]=true;
			b[i+j]=true;
			Queen(i+1);
			cos[j]=false;//撤销标记势力 
			a[i-j+7]=false;
			b[i+j]=false;
			queens[i][j]=false;
		}
	}
}
int main()
{
	Queen(1);
}
