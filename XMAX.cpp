/*
      Author : Sunil Kumar
      ABV-IIITM Gwalior
*/
#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define T() int t; cin>>t;while(t--)
#define CLEAR(a) memset((a),0,sizeof(a))
#define all(v) v.begin(), v.end()
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

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX = 1e5 + 5;

bool cmp(LL x, LL y)
{
	return x>y;
}
int main() 
{
		int n;
		cin>>n;
		LL arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		int pos=0;
		for(int i=60;i>=0;i--)
		{
			int idx;
			LL maxe = -1;
			for(int j=pos;j<n;j++)
			{
				if(arr[j]&(1LL<<i) && arr[j]>maxe)
				{
					maxe=arr[j];
					idx=j;
				}
			}
			if(maxe==-1)
			continue;
			swap(arr[pos],arr[idx]);
			for(int j=0;j<n;j++)
			{
				if(j!=pos && arr[j]&(1LL<<i))
				{
					arr[j]=arr[j]^arr[pos];
				}
			}
			pos++;
		}
		LL res=0LL;
		for(int j=0;j<n;j++)
		{
			res=res^arr[j];
		}
		cout<<res<<"\n";
	return 0;
}