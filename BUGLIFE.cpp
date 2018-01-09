#include <bits/stdc++.h>
#define MAX 2003
using namespace std;

bool vis[MAX];
int clr[MAX];
int parent[MAX];
int last;
void dfs(int s,vector<int> adj[])
{
	vis[s]=true;
	for(int i=0;i<adj[s].size();i++)
	{
		if(!vis[adj[s][i]])
		{
			clr[adj[s][i]]=(clr[s]+1)%2;
			dfs(adj[s][i],adj);
		}
	}
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	for(int c=1;c<=t;c++)
	{
		vector<int> adj[MAX];
		int n,m;
		cin>>n>>m;
		int a,b;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		cout<<"Scenario #"<<c<<":\n";
		memset(vis,false,sizeof(vis));
		memset(clr,-1,sizeof(clr));
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				clr[i]=0;
				dfs(i,adj);
			}
		}
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			if(adj[i].size()>0)
			{
				for(int j=0;j<adj[i].size();j++)
				{
					if(clr[i]==clr[adj[i][j]])
					{
						flag=1;
						break;
					}
				}
			}
			if(flag==1)
			break;
		}
		if(flag==1)
		{
			cout<<"Suspicious bugs found!\n";
		}
		else
		{
			cout<<"No suspicious bugs found!\n";
		}
		
	}
	return 0;
}