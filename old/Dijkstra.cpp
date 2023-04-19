typedef long long ll;
typedef pair<ll,int> P;
const int N=1e5+5,M=2e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
struct Edge{
	int to,nxt;
	ll w;
}edge[M<<1];
int n,m,s,head[N],num_edge;
ll dist[N];

void add_edge(int from,int to,ll w){
	edge[++num_edge].nxt=head[from];
	edge[num_edge].to=to;
	edge[num_edge].w=w;
	head[from]=num_edge;
}

void Dijkstra(int s){
	priority_queue< P,vector<P>,greater<P> > que;//降序less<P>
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	que.push(P(0,s));
	while(!que.empty()){
		P p=que.top();que.pop();
		int u=p.second;
		if(dist[u]<p.first) continue;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			ll w=edge[i].w;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				que.push(P(dist[v],v));
			}
		}
	}
}