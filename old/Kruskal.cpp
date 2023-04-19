typedef long long ll;
const int N=5005,M=200005;
int num_edge,n,m,fa[N],rk[N];
struct Edge{
	int to,from;
	ll w;
}edge[M<<1];

void add_edge(int from,int to,ll w){
	edge[++num_edge].to=to;
	edge[num_edge].from=from;
	edge[num_edge].w=w;
}

bool cmp(Edge a,Edge b){
	return a.w<b.w;
}

void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		rk[i]=0;
	}
}

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(rk[x]<rk[y]){
		fa[x]=y;
	}
	else{
		fa[y]=x;
		if(rk[x]==rk[y]){
			rk[x]++;
		}
	}
}

bool same(int x,int y){
	return find(x)==find(y);
}

ll Kruskal(){
	ll ret=0;
	sort(edge+1,edge+m+1,cmp);
	init();
	for(int i=1;i<=m;i++){
		if(!same(edge[i].to,edge[i].from)){
			ret+=edge[i].w;
			unite(edge[i].to,edge[i].from);
		}
	}
	return ret;
}