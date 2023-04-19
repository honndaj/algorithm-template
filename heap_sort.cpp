#include <cstdio>
#include <iostream>
using namespace std;
#define N 100001

int n, a[N];

void adjust(int k, int len) {
	int t = a[k];
	for(int i = k*2+1; i < len; i =i * 2 + 1){
		if(i < len-1 && a[i] < a[i+1]) i++;
		if(t >= a[i]) break;
		else {
			a[k] = a[i];
			k = i;
		}
	}
	a[k] = t;
}

int main() {
	//freopen("in.txt","r",stdin);
	cin>>n;
	for(int i = 0; i< n;i++) cin>>a[i];
	for(int k = n/2; k >= 0; k--) {// build big root heap
		adjust(k, n);
	}
	for(int i = n-1; i > 0; i--) {
		swap(a[i], a[0]);// swap the bigest(a[0]) to the end;
		adjust(0, i);
	}
	for(int i = 0; i < n; i++) cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}