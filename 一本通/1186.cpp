#include<iostream>
using namespace std;
int a[110];
int* data=a+53;
int main(){
	int n;
	cin>>n;
	int temp;
	for(int i=1;i<=n;i++){
		cin>>temp;
		data[temp]++;
	}
	for(int i=-50;i<=50;i++){
		if(data[i]>n/2){
			cout<<i;
			return 0;
		}
	} 
	cout<<"no";
	return 0;
}
