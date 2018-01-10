#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++){
		int n;
		cin>>n;
		LL a[n+1],DP[n+1];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		DP[0]=a[0];
		DP[1]=max(DP[0],a[1]);
		for(int i=2;i<n;i++){
			DP[i]=max(a[i]+DP[i-2],DP[i-1]);
		}
		cout<<"Case "<<k<<": "<<DP[n-1]<<"\n";
	}
	return 0;
}