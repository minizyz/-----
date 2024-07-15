#include<iostream>
#include<queue>
using namespace std;
struct pos{
	int x;
	int y;
	int walk;
};
int walk_x[7]={0 ,1 ,-1,0 ,0 };
int walk_y[7]={0 ,0 ,0 ,1 ,-1};
int BFS(char mg[25][25],//迷宫 
		int  m,//行数 
		int  n,//列数 
		pos  start,//起点 
		pos  end){//终点 
	bool visited[25][25]={};
	queue<pos> q;
	q.push(start);
	while(!q.empty()){
		pos now=q.front();
		q.pop();
		if(now.x==end.x&&now.y==end.y){
			return now.walk;
		}
		for(int i=1;i<=4;i++){
			pos tmp={now.x+walk_x[i],now.y+walk_y[i],now.walk+1};
			if(tmp.x>=1&&tmp.y>=1&&tmp.x<=m&&tmp.y<=n
			 &&mg[tmp.x][tmp.y]!='#'
			 &&!visited[tmp.x][tmp.y]){
			 	visited[tmp.x][tmp.y]=true;
			 	q.push(tmp);
			}
		}
	}
	return -1;
}
int main()
{
    int m, n;
    while (cin >> m >> n)
    {
    	if(m==0&&m==0){
    		break;
		}
        char mg[25][25];
        pos start,end;
        for(int i=1;i<=m;i++){
        	for(int j=1;j<=n;j++){
        		cin>>mg[i][j];
        		if(mg[i][j]=='@'){
        			start.x=i;
        			start.y=j;
        			start.walk=0;
				}
				if(mg[i][j]=='*'){
        			end.x=i;
        			end.y=j;
        			end.walk=999;
				}
			}
		}
		int ans=BFS(mg,m,n,start,end);
		cout<<ans<<endl;
    }
}
