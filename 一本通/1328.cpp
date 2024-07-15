#include<iostream>
#include<cstdio>
using namespace std;
int a[100005]={},ans=0;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]>a[j])ans++;
		}
	}
	cout<<ans;
}
