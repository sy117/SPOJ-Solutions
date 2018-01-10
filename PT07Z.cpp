/*  
    Longest path in a tree using double bfs
*/
#include <bits/stdc++.h>
#define MAX 10003
using namespace std;

vector<int> adj[MAX];
bool vis[MAX];
int label[MAX];
void bfs(int s)
{
	queue<int> q;
	q.push(s);
	vis[s]=true;
	while(!q.empty())
	{
		int k = q.front();
		q.pop();
		for(int i=0;i<adj[k].size();i++)
		{
			if(!vis[adj[k][i]])
			{
				label[adj[k][i]]=label[k]+1;
				vis[adj[k][i]]=true;
				q.push(adj[k][i]);
			}
		}
	}
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int x,y;
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(vis,false,sizeof(vis));
	memset(label,0,sizeof(label));
	label[1]=0;
	bfs(1);
	int leaf,mx;
	mx=0;
	for(int i=1;i<=n;i++)
	{
		if(label[i]>mx)
		{
			mx = label[i];
			leaf = i;
		}
	}
	memset(vis,false,sizeof(vis));
	memset(label,0,sizeof(label));
	label[leaf]=0;
	bfs(leaf);
	mx=0;
	for(int i=1;i<=n;i++)
	{
		if(label[i]>mx)
		{
			mx = label[i];
		}
	}
	cout<<mx<<"\n";
	return 0;
}