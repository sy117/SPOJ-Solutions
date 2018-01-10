#include <bits/stdc++.h>
using namespace std;

const int N=255;
char mat[N][N];
int vis[N][N];
int n=-1,m=-1;
int sheep=0,wolves=0;
int k=-1,v=-1;

bool valid(int x,int y)
{
	return ((x>=0&&x<n)&&(y>=0&&y<m));
}

void dfs(int x,int y)
{
	vis[x][y]=1;
	if(mat[x][y]=='k')
	   k++;
	if(mat[x][y]=='v')
	   v++;
	if(valid(x+1,y)&&vis[x+1][y]==0&&mat[x+1][y]!='#')
	{
		dfs(x+1,y);
	}
	if(valid(x-1,y)&&vis[x-1][y]==0&&mat[x-1][y]!='#')
	{
		dfs(x-1,y);
	}
	if(valid(x,y+1)&&vis[x][y+1]==0&&mat[x][y+1]!='#')
	{
		dfs(x,y+1);
	}
	if(valid(x,y-1)&&vis[x][y-1]==0&&mat[x][y-1]!='#')
	{
		dfs(x,y-1);
	}
	
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>mat[i][j];
			if(mat[i][j]=='k')
			  sheep++;
			if(mat[i][j]=='v')
			  wolves++;
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mat[i][j]=='k'&&vis[i][j]==0)
			{
				k=0;v=0;
				dfs(i,j);
				if(k>v)
				wolves-=v;
				else
				sheep-=k;
				//cout<<k<<" "<<v<<"\n";
			}
		}
	}
	cout<<sheep<<" "<<wolves<<"\n";
	return 0;
}