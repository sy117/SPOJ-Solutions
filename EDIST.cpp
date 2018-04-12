#include <bits/stdc++.h>
using namespace std;

int fun(string x, string y)
{
	int n,m;
	n = x.length();
	m = y.length();
	int dp[n+1][m+1];
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0)
			{
				dp[i][j] = j;
			}
			else if(j==0)
			{
				dp[i][j] = i;
			}
			else if(x[i-1]==y[j-1])
			{
				dp[i][j] = dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
			}
		}
	}
	return dp[n][m];
}
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		string x, y;
		cin>>x>>y;
		int ans = fun(x, y);
		cout<<ans<<"\n";
	}
	return 0;
}
