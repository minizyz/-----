#include <iostream>
#include <iomanip>
using namespace std;
bool cos[10], a[30], b[30];
bool queens[15][15];
int ans = 0;
void Print()//��ӡ 
{
	++ans;
	cout << "No. " << ans << endl;
	for (int j = 1; j <= 8; j++)
	{
		for (int i = 1; i <= 8; i++)
		{
			cout << (queens[i][j] ? '1' : '0') << ' ';//�����Ӧ����true,��ô��Ӧ���1���������0 
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
			queens[i][j]=true;//������� 
			cos[j]=true;
			a[i-j+7]=true;
			b[i+j]=true;
			Queen(i+1);
			cos[j]=false;//����������� 
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
