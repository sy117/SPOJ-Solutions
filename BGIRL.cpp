#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<bool> vec(N, true);
int id[N];
int size[N];

void sieve()
{
	vec[0]=vec[1]=false;
	for(int i=2;i*i<N;i++)
	{
		for(int j=i*i;j<N;j+=i)
		{
			vec[j]=false;
		}
	}
}

void fill()
{
	for(int i=0;i<N;i++)
	{
		id[i]=i;
		size[i]=1;
	}
}

int root(int x)
{
	while(x!=id[x])
	{
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}

void merge(int x, int y)
{
	int rx,ry;
	rx=root(x);
	ry=root(y);
	if(size[rx]<size[ry])
	{
		id[rx]=id[ry];
		size[ry]+=size[rx];
	}
	else
	{
		id[ry]=id[rx];
		size[rx]+=size[ry];
	}
}
int main()
{
	sieve();
	int t;
	cin>>t;
	while(t--)
	{
		fill();
		int n,m;
		cin>>n>>m;
		int u,v;
		for(int i=0;i<m;i++)
		{
			cin>>u>>v;
			if(root(u)!=root(v))
			{
				merge(u,v);
			}
		}
		int maxSize=-1;
		for(int i=1;i<=n;i++)
		{
			int tmp=root(i);
			int sz=size[tmp];
			if(vec[sz]&&sz>maxSize)
			{
				maxSize=sz;
			}
		}
		cout<<maxSize<<"\n";
	}
	return 0;
}