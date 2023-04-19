#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,M=5e4+5,INF=0x3f3f3f3f;
typedef long long ll;
struct Edge{
	int from,to,cap,flow,cost;
	Edge(int from,int to,int c,int f,int w):from(from),to(to),cap(c),flow(f),cost(w){}
};
vector<Edge> edges;
vector<int> G[N];
int n,m,s,t,a[N],p[N],inq[N],d[N];
ll flow,cost;

bool BellmanFord(){
	memset(d,0x3f,sizeof(d));
	memset(a,0,sizeof(a));
	memset(inq,0,sizeof(inq));
		queue<int> que;
		que.push(s);
		a[s]=INF;p[s]=0;inq[s]=1;d[s]=0;
		while(!que.empty()){
			int x = que.front();que.pop();
			inq[x]=0;
			for(int i=0;i<G[x].size();i++){
				Edge e = edges[G[x][i]];
				if(e.cap>e.flow && d[e.to]>d[x]+e.cost) {
					d[e.to]=d[x]+e.cost;
					p[e.to] = G[x][i];
					a[e.to] = min(a[x],e.cap-e.flow);
					if(!inq[e.to]){
						que.push(e.to);
						inq[e.to]=1;
					}
				}
			}
		}
		if(d[t]==INF) return false;
		flow += a[t];
		cost += (ll)d[t]*(ll)a[t];
		for(int u = t;u != s;u = edges[p[u]].from){
			edges[p[u]].flow+=a[t];
			edges[p[u]^1].flow-=a[t];
		}
		return true;
}


int main(){
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++){
		int from,to,cap,cost;
		cin>>from>>to>>cap>>cost;
		edges.push_back(Edge(from,to,cap,0,cost));
		edges.push_back(Edge(to,from,0,0,-cost));
		int tmp=edges.size();
		G[from].push_back(tmp-2);
		G[to].push_back(tmp-1);
	}
	flow=cost=0;
	while(BellmanFord());
	printf("%lld %lld",flow,cost);
	return 0;
}