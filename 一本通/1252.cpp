#include<iostream>
#include<queue>
using namespace std;
struct pos{
	int x,y,walk=0;
};
int walk_x[5]={0,1,-1,0,0};
int walk_y[5]={0,0,0,1,-1};
char mg[45][45];
bool visited[45][45];
int r,c;
bool OK(int x,int y){
	if(x>=1&&y>=1&&x<=r&&y<=c){//ÔÚÃÔ¹¬ÄÚ 
		if(mg[x][y]=='.'){
			if(!visited[x][y]){
				return true;
			}
		}
	}
	return false;
}
int BFS(int endx,int endy){
	queue<pos> q;
	pos start;
	start.x=1;
	start.y=1;
	start.walk=1;
	q.push(start);
	int ans=0;
	while(!q.empty()){
		pos now=q.front();
		if(now.x==endx&&now.y==endy){
			ans=now.walk;
			break;
		}
		q.pop();
		for(int i=1;i<=4;i++){
			pos temp;
			temp.x=now.x+walk_x[i];
			temp.y=now.y+walk_y[i];
			temp.walk=now.walk+1;
			if(OK(temp.x,temp.y)){
				q.push(temp);
				visited[temp.x][temp.y]=true;
			}
		}
	}
	return ans;
}
int main(){
	cin>>r>>c;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin>>mg[i][j];
		}
	}
	cout<<BFS(r,c);
	return 0; 
}
