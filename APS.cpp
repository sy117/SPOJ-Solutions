#include <bits/stdc++.h>
#define max 10000001
using namespace std;

long long f[max]={0};
long long a[max];
int main()
{
	long long i,j,k;
	f[0]=f[1]=-1;
	for(i=2;i<=sqrt(max);i++)
	{
		for(j=i*i;j<max;j+=i)
		{
			if(f[j]==0||f[j]>i)
			f[j]=i;
		}
	}
	a[0]=a[1]=0;
	for(i=2;i<max;i++)
	{
		if(f[i]==0)
		k=i;
		else
		k=f[i];
		a[i]=a[i-1]+k;
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		printf("%lld\n",a[n]);
	}
}