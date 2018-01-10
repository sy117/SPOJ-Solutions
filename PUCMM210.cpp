#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N=1000005;
const int MOD=1000000003;

LL arr[N];
LL pre[N];

LL modulo(int a,int b){
	LL x=1,y=a;
	while(b>0){
		if(b&1){
			x=(x*y)%MOD;
		}
		y=(y*y)%MOD;
		b/=2;
	}
	return x%MOD;
}
int main() {
	arr[0]=0;
	for(int i=1;i<N;i++){
		arr[i]=(arr[i-1]+modulo(i,3))%MOD;
	}
	pre[0]=0;
	for(int i=1;i<N;i++){
		pre[i]=(pre[i-1]+arr[i])%MOD;
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%lld\n",pre[n]);
	}
	return 0;
}