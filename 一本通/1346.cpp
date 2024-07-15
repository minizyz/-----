#include<iostream>
#include<exception>
using namespace std;
int relation[20005];
int root(int r){
	try{
		cout<<"getting relation["<<r<<"]="<<relation[r]<<endl;
		if(relation[r]==r)return r;
		else return relation[r]=root(r);
	}
	catch(exception& e){
		cout<<"Caught in function \"root\":"<<e.what()<<endl;
	}
}
int main(){
	try{
		int n,m;
		cin>>n>>m;
		int a,b,c,d;
		for(int i=1;i<=20000;i++)relation[i]=i;
		for(int i=1;i<=m;i++){
			cin>>a>>b;
			relation[a]=root(b);
		}
		int q;
		cin>>q;
		for(int i=1;i<=q;i++){
			cin>>c>>d;
			if(root(c)==root(d))cout<<"Yes";
			else cout<<"No";
			cout<<endl;
		}
	}
	catch(exception& e){
		cout<<"Caught in main:"<<e.what()<<endl;
		throw;
	}
	catch(...){
		cout<<"Caught in main:"<<"Other error"<<endl;
		throw;
	}
	return 0;
}
