const int N=20005,M=200005;
const ll INF=1e10;
struct Edge{
	int from,to,nxt;
	ll w;
}edge[M];
int num_edge,head[N],n,m;
ll dist[N];

void add_edge(int from,int to,ll w){
	edge[++num_edge].from=from;
	edge[num_edge].to=to;
	edge[num_edge].w=w;
	head[from]=num_edge;
}

void Bellman_Ford(int s){
	for(int i=1;i<=n;i++) dist[i]=INF;
	dist[s]=0;
	while(1){
		bool flag=0; 
		for(int i=1;i<=num_edge;i++){
			int from=edge[i].from,to=edge[i].to;
			ll w=edge[i].w;
			if(dist[to]>dist[from]+w){
				dist[to]=dist[from]+w;
				flag=1;
			}
		}
		if(!flag) break;
	}
}