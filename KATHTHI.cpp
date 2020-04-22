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
const int MAX = 1e6 + 10;
const int N = 1e3 + 1;

char mapp[N][N];
int dist[N][N];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
void in_it(int R, int C)
{
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			dist[i][j]=INF;
		}
	}
}

bool valid(int x, int y, int R,int C)
{
	return ((x>=0&&x<R)&&(y>=0&&y<C));
}

int binaryBfs(int R, int C)
{
	deque<PI> q;
	q.push_front({0,0});
	dist[0][0]=0;
	while(!q.empty())
	{
		int x,y, wt;
		x = q.front().fi;
		y = q.front().se;
		q.pop_front();
		for(int i=0;i<4;i++)
		{
			int xx = x+dx[i];
			int yy = y+dy[i];
			
			if(valid(xx,yy,R,C))
			{
				int wt = (mapp[x][y]==mapp[xx][yy]) ? 0 : 1;
				if(dist[xx][yy]>dist[x][y]+wt)
				{
					dist[xx][yy] = dist[x][y]+wt;
					if(wt==0)
					q.push_front({xx,yy});
					else
					q.push_back({xx,yy});
				}
				
			}
		}
	}
	return dist[R-1][C-1];
}
int main() 
{
	FIO
	T()
	{
		int R,C;
		cin>>R>>C;
		in_it(R,C);
		char map[R][C];
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				cin>>mapp[i][j];
			}
		}
		int ans = binaryBfs(R,C);
		cout<<ans<<"\n";
	}
	return 0;
}
