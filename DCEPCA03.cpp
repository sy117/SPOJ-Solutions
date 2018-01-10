#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

const int N=10003;

LL phi[N];
LL pre[N];

void cal(){
	for(int i=0;i<N;i++){
		phi[i]=i;
	}
	for(int i=2;i<N;i++){
		if(phi[i]==i){
			phi[i]=i-1;
			for(int j=2*i;j<N;j+=i){
				phi[j]=(phi[j]/i)*(i-1);
		    }
		}
	}
	pre[0]=0;
	for(int i=1;i<N;i++){
		pre[i]=pre[i-1]+phi[i];
	}
}
int main() {
	cal();
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%lld\n",pre[n]*pre[n]);
	}
	return 0;
}