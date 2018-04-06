#include <bits/stdc++.h>
#include <iostream>
#define MOD 1000000007//10e9+7;
#define MAX 1000005
#define T() int t; scanf("%d",&t);while(t--)
#define FOR(i,a,b) for(int (i) = (a); (i) < (b); (i)++)
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); (i)--)
#define CLEAR(a) memset((a),0,sizeof(a))
#define all(v) v.begin(), v.end()
#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d%d",&x,&y);
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld%lld",&x,&y);
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz size
#define ln length

using namespace std;

template<typename T> T gcd(T a, T b){return (b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}

typedef long long int LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef pair<int,int> PI;
typedef pair<LL,LL> PL;


int main() 
{
	
	int n,k;
	si(n);
	int a[n];
	FOR(i,0,n)
	{
		si(a[i]);
	}
	si(k);
	deque<int> dq;
	vector<int> v;
	int mx=0;
	for(int i=0;i<k;i++)
	{
		dq.pb(a[i]);
		mx=max(mx,a[i]);
	}
	v.pb(mx);
	for(int i=k;i<n;i++)
	{
		int z=dq.front();
		dq.pop_front();
		if(z==mx)
		{
			mx=*max_element(dq.begin(),dq.end());
		}
		dq.pb(a[i]);
		mx=max(mx,a[i]);
		v.pb(mx);
	}
	for(auto i=v.begin();i!=v.end();i++)
	{
		printf("%d ",*i);
	}
	return 0;
}