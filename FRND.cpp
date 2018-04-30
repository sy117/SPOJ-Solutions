#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int main() 
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<a[0]<<"\n";
		return 0;
	}
	LL zero,one;
	LL res=0;
	for(int k=0;k<32;k++)
	{
		one=0,zero=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]&(1<<k))
			one++;
			else
			zero++;
		}
		res+=(one*zero*(1<<k));
	}
	cout<<res<<"\n";
	return 0;
}