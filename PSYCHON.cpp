#include <bits/stdc++.h>
using namespace std;

const int N = 10000011;

int main() 
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int cnt,even,odd;
		even=odd=0;
		for(int i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				cnt=0;
				while(n%i==0)
				{
					cnt++;
					n/=i;
				}
				if(cnt&1)
		     	odd++;
			    else
	            even++;
			}
			
		}
		if(n>1)
		odd++;
		if(even>odd)
		{
			printf("Psycho Number\n");
		}
		else
		{
			printf("Ordinary Number\n");
		}
	}
	return 0;
}