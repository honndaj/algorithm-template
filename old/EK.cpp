#include<bits/stdc++.h>
using namespace std;
const int N=205,M=5005,INF=0x3f3f3f3f;
typedef long long ll;
struct Edge{
	int from,to,cap,flow;
	Edge(int from,int to,int c,int f):from(from),to(to),cap(c),flow(f){}
};
vector<Edge> edges;
vector<int> G[N];
int n,m,s,t,a[N],p[N];
ll flow,cap;


int main(){
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++){
		int from,to,cap;
		cin>>from>>to>>cap;
		edges.push_back(Edge(from,to,cap,0));
		edges.push_back(Edge(to,from,0,0));
		int tmp=edges.size();
		G[from].push_back(tmp-2);
		G[to].push_back(tmp-1);
	}
	flow=0;
	for(;;){
		memset(a,0,sizeof(a));
		queue<int> que;
		que.push(s);
		a[s]=INF;
		while(!que.empty()){
			int x = que.front();que.pop();
			for(int i=0;i<G[x].size();i++){
				Edge e = edges[G[x][i]];
				if(!a[e.to] && e.cap>e.flow) {
					p[e.to] = G[x][i];
					a[e.to] = min(a[x],e.cap-e.flow);
					que.push(e.to);
				}
			}
			if(a[t]) break;
		}
		if(!a[t]) break;
		for(int u = t;u != s;u = edges[p[u]].from){
			edges[p[u]].flow+=a[t];
			edges[p[u]^1].flow-=a[t];
		}
		flow+=a[t];
	}
	cout<<flow;
	return 0;
}