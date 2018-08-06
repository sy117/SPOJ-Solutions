#include <bits/stdc++.h>
#define max 1000003
using namespace std;
int rev(int q)
{
	int r=0;
	while(q)
	{
		r=r*10+q%10;
		q/=10;
	}
	return r;
}

vector<bool>prime(max,true);
int s[max];
//char st[10];
int main()
{
	prime[0]=prime[1]=false;
	int i,j,k,f1,f2,x,y,z;
	for(i=2;i<sqrt(max);i++)
	{
		if(prime[i])
		{
		    for(j=i*i;j<max;j+=i)
			    prime[j]=false;
		}
	}
	s[0]=s[1]=0;
	s[2]=1;s[3]=2;s[4]=2;s[5]=3;s[6]=3;
	s[7]=4;s[8]=4;s[9]=4;s[10]=4;
	for(i=11;i<max;i++)
	{
		f1=f2=0;
		x=i;
		z=0;
		k=0;
		if(prime[x])
		{
			k=1;
			while(x)
			{
				y=x%10;
				if(y==0)f1=1;
				z=z*10+y;
				if(prime[rev(z)]==false)
				f2=1;
				x/=10;
			}
		}
		
		if(f1==0&&f2==0&&k==1)
		s[i]=s[i-1]+1;
		else
		s[i]=s[i-1];
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",s[n]);
	}
	return 0;
}