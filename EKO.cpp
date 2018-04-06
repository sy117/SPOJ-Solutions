#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int N,M;
	scanf("%lld%lld",&N,&M);
	long long int a[N],i,max=0;
	for(i=0;i<N;i++)
	{
	scanf("%lld",&a[i]);
	if(a[i]>max)
	   max=a[i];
	}
	long long int low,high,mid,wood,h=0;
	low=0;
	high=max;
	while(low<=high)
	{
	
		mid=low+((high-low)/2);
		wood=0;
		for(i=0;i<N;i++)
		{
		if((a[i]-mid)>0)
		  wood+=(a[i]-mid);
		}
		 if(wood>M)
		 {
		 low=mid+1;
		 if(mid>h)
		 h=mid;
		 }
		 else if(wood<M)
		 high=mid-1;
		 else 
		 {
			h=mid;
		    break;
		 }
	}	
	printf("%lld\n",h);
	return 0;
}