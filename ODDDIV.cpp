#include <bits/stdc++.h>
#define N 100003
using namespace std;

typedef long long int LL;
vector<LL> v[N];

LL ndiv(LL x)
{
	LL cnt,res=1;
	for(LL i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			cnt=0;
			while(x%i==0)
			{
				x/=i;
				cnt++;
			}
			res*=(2*cnt+1);
		}
	}
	if(x>1)
	res*=3;
	return res;
}

void pre()
{
	for(LL i=1;i<N;i++)
	{
		v[ndiv(i)].push_back(i*i);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	pre();
	LL t;
	cin>>t;
	while(t--)
	{
		LL k,l,r;
		cin>>k>>l>>r;
		LL a,b,ans;
		a = lower_bound(v[k].begin(), v[k].end(), l) - v[k].begin();
		b = upper_bound(v[k].begin(), v[k].end(), r) - v[k].begin();
		ans = b-a;
		cout<<ans<<"\n";
	}
	return 0;
}