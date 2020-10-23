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
vector<int> res;
int deg[N];


void topSort(int n){
	priority_queue<int>PQ;
	for(int i=1; i<=n; i++){
		if(deg[i]==0){
			PQ.push(-i);
		}
	}
	while(!PQ.empty()){
		int x = PQ.top();
		x = -x;
		PQ.pop();
		res.pb(x);
		for(auto to: adj[x]){
			deg[to] --;
			if(deg[to]==0){
				PQ.push(-to);
			}
		}
	}
	
}

int main() 
{
	int n, m, u, v;
	cin >> n >> m;
	memset(deg, 0, sizeof(deg));
	for(int i=0; i<m; i++){
		cin >> u >> v;
		adj[u].pb(v);
		deg[v] ++;
	}
	topSort(n);

	if(res.size() != n){
		cout << "Sandro fails.\n";
	}
	else{
		for(auto ele: res){
			cout << ele << " ";
		}
		cout << "\n";
	}
	return 0;
}