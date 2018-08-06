#include <bits/stdc++.h>
#define MAX 50001
#define MOD 1000000007
using namespace std;

int main()
{
	int a[MAX]={0};
	a[0]=a[1]=-1;
	int primes[MAX];
	int i,j,k;
	for(i=2;i<sqrt(MAX);i++)
	{
		for(j=i*i;j<MAX;j+=i)
		{
			a[j]=-1;
		}
	}
	k=0;
	for(i=0;i<MAX;i++)
	{
		if(a[i]==0)
		primes[k++]=i;
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,z,count,power;
	    scanf("%d",&n);
	    long long ans=1;
	    for(z=0;primes[z]<=n;z++)
	    {
	    	power=0;
		    for(i=1;;i++)
		    {
			   count=n/pow(primes[z],i);
			   if(count==0)
			   break;
			   power+=count;
		    }
		   ans=ans*((power+1)%MOD);
		   ans%=MOD;
	    }
	    cout<<ans<<endl;
	}
	
	return 0;
}