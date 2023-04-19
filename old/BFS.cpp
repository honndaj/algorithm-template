#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int n,m,sx,sy,dis[505][505],dx[8]={1,1,-1,-1,2,2,-2,-2},dy[8]={2,-2,2,-2,1,-1,1,-1};

void bfs(){
	queue<P> que;
	dis[sx][sy]=0;
	que.push(P(sx,sy));
	while(!que.empty()){
		P p=que.front();que.pop();
		for(int i=0;i<8;i++){
			int x=p.first+dx[i],y=p.second+dy[i];
			if(x<=n&&x>=1&&y<=m&&y>=1&&dis[x][y]==-1){
				que.push(P(x,y));
				dis[x][y]=dis[p.first][p.second]+1;
			}
		}
	}
}

int main(){
	cin>>n>>m>>sx>>sy;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=-1;
		}
	}
	bfs();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%-5d",dis[i][j]);
		}
		putchar('\n'); 
	}
	return 0;
}