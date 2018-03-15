/*
    Problem : http://www.spoj.com/problems/ALIEN/
    Approach : Two Pointer
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 100005;

int main() 
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		LL sum;
		scanf("%d%lld",&n,&sum);
		LL a[N];
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		int d,l=0,r=0,size=0;
		LL ans=0,s=0;
		while(l<n)
		{
			while(r<n && s+a[r]<=sum)
			{
				s+=a[r];
				r++;
			}
			d=(r-l);
			if(d>size)
			{
				ans=s;
				size=d;
			}
			else if(d==size)
			{
				ans=min(ans,s);
			}
			s-=a[l];
			l++;
		}
		printf("%lld %d\n",ans,size);
	}
	return 0;
}