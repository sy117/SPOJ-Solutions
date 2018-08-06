/*
	          ********************
                                                 
*/

#include <bits/stdc++.h>
#include <iostream>
#define MOD 1000000007//;
#define MAX 1000005
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define T() int t; scanf("%d",&t);while(t--)
#define REP(i,a,b) for(int (i) = (a); (i) < (b); (i)++)
#define rep(i,n) for(int (i) = (0); (i) < (n); (i)++)
#define REV(i,a,b) for(int (i) = (a)-1; (i) >= (b); (i)--)
#define CLEAR(a) memset((a),0,sizeof(a))
#define all(v) v.begin(), v.end()
#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d%d",&x,&y);
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld%lld",&x,&y);
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz size
#define ln length
#define itr iterator;

using namespace std;

typedef long long int LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef pair<int,int> PI;
typedef pair<LL,LL> PL;

template<typename T> T gcd(T a, T b){return (b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
template<typename T> T pwr(T base, T p, T mod){
LL ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;}


int main() 
{
	int phi[MAX];
	int i,j;
	for(i=1;i<MAX;i++)
	{
		phi[i]=i;
	}
	for(i=2;i<MAX;i++)
	{
		if(phi[i]==i)
		{
			phi[i]=i-1;
			for(j=2*i;j<MAX;j+=i)
			{
				phi[j] = (phi[j]/i)*(i-1);
			}
		}
	}
	T()
	{
		int n;
		si(n);
		pi(phi[n]);
	}
	return 0;
}