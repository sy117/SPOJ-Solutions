#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
	int n;
	while(1)
	{
		cin>>n;
		if(n==0)
		break;
		vector<ll>v(n);
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll ans = 0;
		for(int i=0;i<n-2;i++)
		{
			for(int j=i+1;j<n-1;j++)
			{
				ans+=n-(upper_bound(v.begin(),v.end(),v[i]+v[j])-v.begin());
			}
		}
		cout<<ans<<"\n";
		
	}
	return 0;
}