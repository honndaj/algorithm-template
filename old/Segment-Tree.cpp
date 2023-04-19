typedef long long ll;
const int N=1e5+5,M=1e5+5;
int n,m;
ll maxn[N<<2],sum[N<<2],w[N],lazy[N<<2];

ll max(ll a,ll b){
	return a>b?a:b;
}

void update(int k){
	sum[k]=sum[k<<1]+sum[k<<1|1];
}

void pushdown(int k,int l,int r){
	if(l==r||lazy[k]==0) return;
	int mid=(l+r)>>1;
	sum[k<<1]+=lazy[k]*(mid-l+1);
	sum[k<<1|1]+=lazy[k]*(r-mid);
	lazy[k<<1]+=lazy[k];
	lazy[k<<1|1]+=lazy[k];
	lazy[k]=0;
}

void build(int k,int l,int r){
	if(l==r){
		maxn[k]=sum[k]=w[l];
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	update(k);
}

void modify_interval(int k,int l,int r,int a,int b,ll num){
	if(l>b||r<a){
		return;
	}
	pushdown(k,l,r);
	if(a<=l&&r<=b){
		sum[k]+=num*(r-l+1);
		lazy[k]+=num;
		return;
	}
	int mid=(l+r)>>1;
	modify(k<<1,l,mid,a,b,num);
	modify(k<<1|1,mid+1,r,a,b,num);
	update(k);
}

void modify(int k,int l,int r,int tar,ll num){
	if(l==r){
		maxn[k]=sum[k]=num;
		return;
	}
	pushdown(k,l,r);
	int mid=(l+r)>>1;
	if(tar<=mid) modify(k<<1,l,mid,tar,num);
	else modify(k<<1|1,mid+1,r,tar,num);
	update(k);
}

ll query_sum(int k,int l,int r,int a,int b){
	if(l>b||r<a){
		return 0;
	}
	pushdown(k,l,r);
	if(a<=l&&r<=b){
		return sum[k];
	}
	int mid=(l+r)>>1;
	return query_sum(k<<1,l,mid,a,b)+query_sum(k<<1|1,mid+1,r,a,b);
}

ll query_max(int k,int l,int r,int a,int b){
	if(l>b||r<a){
		return 0;
	}
	pushdown(k,l,r);
	if(a<=l&&r<=b){
		return maxn[k];
	}
	int mid=(l+r)>>1;
	return max(query_max(k<<1,l,mid,a,b),query_max(k<<1|1,mid+1,r,a,b));
}