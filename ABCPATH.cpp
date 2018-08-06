#include <bits/stdc++.h>
using namespace std;

const int N=52;
char mat[N][N];
int vis[N][N];
int d[N][N];
int R,C;

bool valid(int x,int y)
{
	return ((x>=0&&x<R)&&(y>=0&&y<C));
}
void fill()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			vis[i][j]=0;
			d[i][j]=0;
		}
	}
}

void dfs(int x,int y)
{
	vis[x][y]=1;
	if(valid(x+1,y)&&vis[x+1][y]==0&&mat[x+1][y]==mat[x][y]+1)
	{
		d[x+1][y]=d[x][y]+1;
		dfs(x+1,y);
	}
	if(valid(x-1,y)&&vis[x-1][y]==0&&mat[x-1][y]==mat[x][y]+1)
	{
		d[x-1][y]=d[x][y]+1;
		dfs(x-1,y);
	}
	if(valid(x,y+1)&&vis[x][y+1]==0&&mat[x][y+1]==mat[x][y]+1)
	{
		d[x][y+1]=d[x][y]+1;
		dfs(x,y+1);
	}
	if(valid(x,y-1)&&vis[x][y-1]==0&&mat[x][y-1]==mat[x][y]+1)
	{
		d[x][y-1]=d[x][y]+1;
		dfs(x,y-1);
	}
	if(valid(x-1,y-1)&&vis[x-1][y-1]==0&&mat[x-1][y-1]==mat[x][y]+1)
	{
		d[x-1][y-1]=d[x][y]+1;
		dfs(x-1,y-1);
	}
	if(valid(x-1,y+1)&&vis[x-1][y+1]==0&&mat[x-1][y+1]==mat[x][y]+1)
	{
		d[x-1][y+1]=d[x][y]+1;
		dfs(x-1,y+1);
	}
	if(valid(x+1,y+1)&&vis[x+1][y+1]==0&&mat[x+1][y+1]==mat[x][y]+1)
	{
		d[x+1][y+1]=d[x][y]+1;
		dfs(x+1,y+1);
	}
	if(valid(x+1,y-1)&&vis[x+1][y-1]==0&&mat[x+1][y-1]==mat[x][y]+1)
	{
		d[x+1][y-1]=d[x][y]+1;
		dfs(x+1,y-1);
	}
}
int main()
{
	for(int k=1;;k++)
	{
		fill();
		cin>>R>>C;
		if(R==0&&C==0)
		break;
		int cnt=0;
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				cin>>mat[i][j];
				if(mat[i][j]=='A')
				cnt++;
			}
		}
		if(cnt==0)
		{
			cout<<"Case "<<k<<": "<<cnt<<"\n";
			continue;
		}
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				if(mat[i][j]=='A'&& vis[i][j]==0)
				{
					d[i][j]=0;
					dfs(i,j);
				}
			}
		}
		int ans=0;
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				if(d[i][j]>ans)
				ans=d[i][j];
			}
		}
		ans++;
		//Case 1: 4
		cout<<"Case "<<k<<": "<<ans<<"\n";
	}
	return 0;
}