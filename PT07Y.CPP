#include <bits/stdc++.h>
#define MAX 10003
using namespace std;

vector<int> adj[MAX];
bool vis[MAX];

void dfs(int s)
{
	vis[s]=true;
	for(auto x:adj[s])
	{
		if(!vis[x])
		{
			dfs(x);
		}
	}
}

int main() 
{
	int n,m;
	cin>>n>>m;
	int a,b;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if(m!=n-1)
	{
		cout<<"NO\n";
		return 0;
	}
	memset(vis,false,sizeof(vis));
	dfs(1);
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		cout<<"NO\n";
	}
	else
	{
		cout<<"YES\n";
	}
	return 0;
}