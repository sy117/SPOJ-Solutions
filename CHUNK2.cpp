#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> prime;
vector<int> adj[N];
bool vis[N];
int cnt;

void sieve()
{
	vector<bool> vec(N*20, true);
	vec[0]=vec[1]=false;
	for(int i=2;i*i<N*20;i++)
	{
		if(vec[i])
		{
			for(int j=i*i;j<N*20;j+=i)
			{
				vec[j]=false;
			}
		}
	}
	for(int i=2;i<N*20;i++)
	{
		if(vec[i])
		{
			prime.push_back(i);
		}
	}
}
void dfs(int s)
{
	vis[s]=1;
	cnt++;
	for(auto x:adj[s])
	{
		if(!vis[x])
		{
			dfs(x);
		}
	}
}

void fill()
{
	for(int i=0;i<N;i++)
	{
		adj[i].clear();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	sieve();
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		if(m==0)
		{
			cout<<"-1\n";
			continue;
		}
		int u,v;
		for(int i=0;i<m;i++)
		{
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		memset(vis,false,sizeof(vis));
		int k=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				cnt=0;
				dfs(i);
				k=max(k,cnt);
			}
		}
		cout<<prime[k-1]<<"\n";
		fill();
	}
	return 0;
}