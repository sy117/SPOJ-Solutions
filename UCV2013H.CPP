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

int N,M;
int arr[251][251];
int vis[251][251];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int cnt;
bool valid(int x,int y)
{
	return ((x>=0&&x<N)&&(y>=0&&y<M));
}

void fill()
{
	for(int i=0;i<251;i++)
	{
		for(int j=0;j<251;j++)
		{
			vis[i][j]=0;
		}
	}
}
void dfs(int x,int y)
{
	vis[x][y]=1;
	cnt++;
	for(int i=0;i<4;i++)
	{
		int a,b;
		a=x+dx[i];
		b=y+dy[i];
		if(valid(a,b)&&arr[a][b]==1&&vis[a][b]==0)
		{
			dfs(a,b);
		}
	}
}
int main() 
{
	while(1)
	{
		cin>>N>>M;
		if(N==0&&M==0)
		break;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				cin>>arr[i][j];
			}
		}
		fill();
		int ans=0;
		map<int,int> mm;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				if(arr[i][j]==1 && vis[i][j]==0)
				{
					cnt=0;
					dfs(i,j);
					ans++;
					mm[cnt]++;
				}
			}
		}
		cout<<ans<<"\n";
		for(auto p:mm)
		{
			cout<<p.fi<<" "<<p.se<<"\n";
		}
	}
	
	return 0;
}
