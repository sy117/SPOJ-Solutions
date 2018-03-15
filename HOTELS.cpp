/*
    Problem : http://www.spoj.com/problems/HOTELS/
    Approach : Binary Search
    Explanation: Store cumulative sum at each index in a separate array pre[].
                 Treat each index as startIndex of the required contiguous subarray,
                 find a corresponding endIndex such that : 
                 pre[endIndex]-pre[startIndex-1] < = SUM
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 300005;

LL a[N],pre[N];
int main()
{
	int n;
	LL sum;
	cin>>n>>sum;
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	pre[0]=0;
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i];
	}
	LL ans=0;
	for(int i=1;i<=n;i++)
	{
		int lo,hi,mid;
		lo=i;hi=n;
		while(lo<=hi)
		{
			mid=(lo+hi)/2;
			if(pre[mid]-pre[i-1]<=sum)
			{
				ans=max(ans,pre[mid]-pre[i-1]);
				lo=mid+1;
			}
			else
			{
				hi=mid-1;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}