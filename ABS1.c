#include<stdio.h>
 
int main() 
{
	int t;
	int n,i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		long long int a[n],sum;
		for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
		j=1;
		k=0;
		sum=0;
		while(j<n)
		{
		    sum=sum+((n-j)*(a[n-k]-a[k+1]));
		    j=j+2;
		    k++;
		}
		printf("%lld\n",sum);
	}
	return 0;
} 