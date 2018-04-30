#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000005;
vector<int> vec(MAX,1);
vector<int> p;

void fun()
{
	vec[0]=vec[1]=0;
	for(int i=2;i<MAX;i++)
	{
		if(vec[i]==1)
		{
			for(int j=i;j<MAX;j+=i)
			{
				vec[j]=i;
			}
		}
	}
}
int main()
{
	fun();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		unordered_map<int,int> um;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			while(arr[i]>1)
			{
				int x = vec[arr[i]];
				um[x]++;
				while(arr[i]%x==0)
				{
					arr[i]/=x;
				}
			}
		}
		for(int i=2;i<MAX;i++)
		{
			if(vec[i]==i && !um[i])
			{
				cout<<i<<"\n";
				break;
			}
		}
	}
	return 0;
}