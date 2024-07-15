#include<iostream>
using namespace std;
char lake[120][120];
int walk_x[10]={0,1,-1,0,0,1,1,-1,-1};
int walk_y[10]={0,0,0,1,-1,1,-1,1,-1};
void DFS(int x,int y){
	lake[x][y]='.';
	for(int i=1;i<=8;i++){
		int tmpx=x+walk_x[i];
		int tmpy=y+walk_y[i];
		if(lake[tmpx][tmpy]=='W'){
			DFS(tmpx,tmpy);
		}
	} 
}
int main(){
	int N,M;
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin>>lake[i][j];
		}
	} 
	int ans=0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(lake[i][j]=='W'){
				ans++;
				DFS(i,j);
			}
		}
	} 
	cout<<ans;
	return 0;
}
