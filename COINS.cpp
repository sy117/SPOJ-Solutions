#include <bits/stdc++.h>

using namespace std;

map<long long,long long>dp;

long long fun(long long n)
{
	long long val;
	if(n==0)
	return 0;
	if(dp[n]!=0)
	{
		return dp[n];
	}
	else
	{
		val=max(n,fun(n/2)+fun(n/3)+fun(n/4));
		dp[n]=val;
	}
	return dp[n];
}


int main()
{
	long long N;
	while(scanf("%lld",&N)!=EOF)
	{
		long long ans; 
		ans=fun(N);
		printf("%lld\n",ans);
	}
	
	return 0;
}
