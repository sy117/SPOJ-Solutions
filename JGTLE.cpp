#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int main() {
	int tc;
	cin>>tc;
	for(int i=1;i<=tc;i++){
		LL a,b,c,ans;
		cin>>a>>b>>c;
		ans=a*((b*(b+1))/2)*((c*(c+1))/2);
		cout<<"Case "<<i<<": "<<ans<<"\n";
	}
	return 0;
}