/*
      Author : sy_117
*/
#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define T() int t; cin>>t;while(t--)
#define _fill(a) memset((a),0,sizeof(a))
#define _all(v) v.begin(), v.end()
#define _sort(v) sort(_all(v))
#define _lb(v,x) lower_bound(_all(v),x) - v.begin()
#define _ub(v,x) upper_bound(_all(v),x) - v.begin()
#define _print(v) for(auto x:v){cout<<x<<" ";}
#define fi first
#define se second
#define pb push_back
#define mp make_pair


using namespace std;
     
template<typename T> T gcd(T a, T b){return (b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
template<typename T> T setbit(T x){return __builtin_popcount(x);}

typedef long long int LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef pair<int,int> PI;
typedef pair<LL,LL> PL;

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX = 1e6 + 10;
const int N = 1e4 + 5;

vector<int> adj[N];
unordered_set<int> cutv;
bool vis[N];
int in[N], low[N];
int timer = 0;

void _init_(){
	for(int i=0; i<N; i++){
		adj[i].clear();
		vis[i] = false;
		in[i] = low[i] = -1;
	}
	cutv.clear();
}
void dfs(int src, int par){
	vis[src] = true;
	in[src] = low[src] = timer++;
	int child = 0;
	for(auto to: adj[src]){
		if(to == par) continue;
		if(vis[to]){
			low[src] = min(low[src], in[to]);
		}
		else{
			dfs(to, src);
			child ++;
			low[src] = min(low[src], low[to]);
			if(low[to] >= in[src] and par != -1){
				cutv.insert(src);
			}
		}
	}
	if(par == -1 and child > 1){
		cutv.insert(src);
	}
}
int main() 
{
	int TC = 1e6;
	while(TC--){
		_init_();
		int n, m;
		cin >> n >> m;
		if(n==0 and m==0) break;
		int u, v;
		for(int i=0; i<m; i++){
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs(1, -1);
		cout << cutv.size() << "\n";
	}
	return 0;
}