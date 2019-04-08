#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

typedef pair<int, int> PI;

unordered_map<int,int> um;

void pre()
{
	for(int i=1000;i<10000;i++)
	{
		int flag=0;
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		um[i]++;
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	pre();
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		if(!um[a] || !um[b])
		{
			cout<<"Impossible\n";
			continue;
		}
		int ans=-1;
		bool vis[100000];
		memset(vis,false,sizeof(vis));
		queue<PI> q;
		q.push({a,0});
		while(!q.empty())
		{
			PI tmp = q.front();
			q.pop();
			int x,y;
			x=tmp.fi;
			y=tmp.se;
			vis[x]=true;
			if(x==b)
			{
				ans=y;
				break;
			}
			int arr[4]={0};
			int k=3;
			while(x)
			{
				arr[k--]=x%10;
				x/=10;
			}
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<10;j++)
				{
					if(i==0)
					{
						if(j>0 && j!=arr[i])
						{
							int val=arr[i];
							arr[i]=j;
							int num=0;
							for(int k=0;k<4;k++)
							num = num*10+arr[k];
							if(um[num] && !vis[num])
							{
								q.push({num, y+1});
								vis[num]=true;
							}
							arr[i]=val;
						}
					}
					else
					{
						if(j!=arr[i])
						{
							int val=arr[i];
							arr[i]=j;
							int num=0;
							for(int k=0;k<4;k++)
							num = num*10+arr[k];
							if(um[num] && !vis[num])
							{
								q.push({num, y+1});
								vis[num]=true;
							}
							arr[i]=val;
						}
					}
				}
			}
		}
		if(ans==-1)
		cout<<"Impossible\n";
		else
		cout<<ans<<"\n";
	}
	return 0;
}