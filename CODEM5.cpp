#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int cnt,sum,ans=999999;
		for(int i=0;i<(1<<n);i++)
		{
			cnt=0;sum=0;
			for(int j=0;j<n;j++)
			{
				if(i&(1<<j))
				{
					cnt++;
					sum+=a[j];
				}
			}
			if(sum==k)
			{
				ans=min(ans,cnt);
			}
		}
		if(ans==999999)
		cout<<"impossible\n";
		else
		cout<<ans<<"\n";
	}
	return 0;
}