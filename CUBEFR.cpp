#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int main()
{
	long int arr[MAX]={0};
	long int i,j,k;
	for(i=2;i<101;i++)
	{
		k=i*i*i;
		for(j=1;k*j<MAX;j++)
		{
			arr[k*j]=-1;
		}
	}
	j=0;
	for(i=0;i<MAX;i++)
	{
		if(arr[i]==0)
		arr[i]=j++;
	}
	long int t,n,p,l,m;
	scanf("%ld",&t);
	for(l=1;l<=t;l++)
	{
		scanf("%ld",&n);
		if(arr[n]==-1)
		{
			printf("Case %ld: Not Cube Free\n",l);
		}
		else 
		{
			printf("Case %ld: %ld\n",l,arr[n]);
		}
	}
	
	return 0;
}