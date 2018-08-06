#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int main()
{
	long long ds[MAX],i,j,k;
	ds[0]=0;
	ds[1]=1;
	
	for(i=2;i<MAX;i++)
	{
		ds[i]=1;
	}
	for(i=2;i<MAX;i++)
	{
		for(j=2;j*i<MAX;j++)
		{
			ds[j*i]+=i;
		}
	}
	
	long long a[MAX];
	a[0]=a[1]=0;
	a[2]=1;
	a[3]=2;
	a[4]=5;
	a[5]=6;
	for(i=6;i<MAX;i++)
	{
		a[i]=a[i-1]+ds[i];
	}
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	long long n;
    	scanf("%lld",&n);
    	printf("%lld\n",a[n]);
    }
	return 0;
}