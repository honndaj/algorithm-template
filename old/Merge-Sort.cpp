typedef long long ll;
int n,a[N],t[N];
ll ans;

void merge(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	merge(l,mid);merge(mid+1,r);
	for(int i=l;i<=r;i++) t[i]=a[i];
	int p=l,q=mid+1,i=l;
	while(p<=mid&&q<=r){
		if(t[p]<=t[q]){
			a[i++]=t[p++];
		}
		else{
			ans+=mid-p+1;
			a[i++]=t[q++];
		}
	}
	while(p<=mid) a[i++]=t[p++];
	while(q<=r) a[i++]=t[q++];
}