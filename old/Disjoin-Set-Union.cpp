int fa[N],rk[N],n,m,p;

void init(){
	for(int i=1;i<=n;++i){
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
