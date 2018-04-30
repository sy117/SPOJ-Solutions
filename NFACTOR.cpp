#include <bits/stdc++.h>
#define MAX 1000001
 
using namespace std;
int p[MAX];
int arr[11][MAX];
int main()
{
	p[MAX]={0};
	int i,j,k;
	for(i=2;i<MAX;i++)
	{
		if(p[i]==0)
		{
			for(j=1;i*j<MAX;j++)
			{
				p[i*j]++;
			}
		}
	}
	
	for(i=0;i<11;i++)
	{
		for(j=0;j<MAX;j++)
		{
			arr[i][j]=0;
		}
	}
	
	for(i=0;i<11;i++)
	{
		for(j=1;j<MAX;j++)
		{
			if(p[j]==i)
			arr[i][j]=arr[i][j-1]+1;
			else
			arr[i][j]=arr[i][j-1];
			
		}
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,n,ans;
		scanf("%d%d%d",&a,&b,&n);
		ans=arr[n][b]-arr[n][a-1];
		printf("%d\n",ans);
	}
	return 0;
} 