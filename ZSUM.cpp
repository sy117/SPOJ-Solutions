#include <bits/stdc++.h>
#define mod 10000007
#define ll long long int
using namespace std;

ll modulo(ll a,ll b,ll c)
{
	ll x=1,y=a;
	while(b>0)
	{
		if(b%2==1)
		{
			x=(x*y)%c;
		}
		y=(y*y)%c;
		b/=2;
	}
	return x%c;
}


int main()
{
	ll n,k;
	while(1)
	{
		scanf("%lld%lld",&n,&k);
		if(n==0&&k==0)
		break;
		ll p,q,r,s,t,u,ans;
		p=(2*(modulo(n-1,k,mod)%mod))%mod;
		q=(2*(modulo(n-1,n-1,mod)%mod))%mod;
		r=(modulo(n,k,mod))%mod;
		s=(modulo(n,n,mod))%mod;
		t=(p+q)%mod;
		u=(r+s)%mod;
		ans=(t+u)%mod;
		printf("%lld\n",ans);
	}
	
	return 0;
}