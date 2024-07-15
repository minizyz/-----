#include<iostream>
using namespace std; 
int main(){
	long long b,p,k;
	cin>>b>>p>>k;
	long long ans=1;
	for(int i=1;i<=p;i++){
		ans=ans*b%k;
	}
	cout<<b<<'^'<<p<<" mod "<<k<<'='<<ans;
}
