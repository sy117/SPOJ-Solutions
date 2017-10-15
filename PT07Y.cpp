/*
    Check two conditoins:
    1. number of edges should be n-1
    2. all node should have same parent 
*/
#include <bits/stdc++.h>
#include <iostream>
#define MOD 1000000007//10e9+7;
#define MAX 10005
#define T() int t; scanf("%d",&t);while(t--)
#define FOR(i,a,b) for(int (i) = (a); (i) < (b); (i)++)
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); (i)--)
#define CLEAR(a) memset((a),0,sizeof(a))
#define all(v) v.begin(), v.end()
#define si(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define pi(x) printf("%d\n",x)
#define pll(x) printf("%lld\n",x)
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;

template<typename T> T gcd(T a, T b){return (b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int id[MAX];
int size[MAX];
void fill(int n)
{
	FOR(i,0,n+1)
	{
		id[i] =i;
		size[i] =1;
	}
}
int root(int x)
{
	while(id[x]!=x)
	{
		id[x]=id[id[x]];
		x = id[x];
	}
	return x;
}
void union1(int a,int b)
{
	int ra,rb;
	ra = root(a);
	rb = root(b);
	if(size[ra]<size[rb])
	{
		id[ra] = id[rb];
		size[rb]+=size[ra];
	}
	else
	{
		id[rb] = id[ra];
		size[ra]+=size[rb];
	}
}
int main() 
{
	int n,m,u,v;
	si(n);si(m);
	if(m!=n-1)
	{
		printf("NO\n");
		return 0;
	}
	fill(n);
	int mn,mx;
	mn = INT_MAX;
	mx=0;
	FOR(i,0,m)
	{
		si(u);si(v);
		if(u<mn)
		mn=u;
		if(v>mx)
		mx=v;
		if(root(u)!=root(v))
		{
			union1(u,v);
		}
	}
	int count=0;
	FOR(i,mn,mx+1)
	{
	if(root(i)==root(mn))
	count++;
	}
	if(count==n)
	printf("YES\n");
	else
	{
		printf("NO\n");
	}
	return 0;
}