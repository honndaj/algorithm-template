void add(int x,int k){
	while(x<=n){
		t[x]+=k;
		x+=x&-x;
	}
}

int sum(int x){
	int ret=0;
	while(x>0){
		ret+=t[x];
		x-=x&-x;
	}
	return ret;
}