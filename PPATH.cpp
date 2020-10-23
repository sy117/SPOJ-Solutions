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
const int N = 1e5 + 5;

unordered_map<int, vector<int>> adj;
unordered_map<int, int> vis;
unordered_map<int, int> dist;

bool diffOne(int a, int b){
	int cnt = 0;
	while(a>0){
		if(a%10 != b%10){
			cnt ++;
		}
		a /= 10;
		b /= 10;
	}
	return (cnt==1);
}
void createGraph(){
	vector<int> primes;
	for(int i=1000; i<10000; i++){
		bool flag = true;
		for(int j=2; j*j<=i; j++){
			if(i%j==0){
				flag = false;
				break;
			}
		}
		if(flag){
			primes.pb(i);
		}
	}
	for(int i=0; i<primes.size(); i++){
		for(int j=i+1; j<primes.size(); j++){
			if(diffOne(primes[i], primes[j])){
				adj[primes[i]].pb(primes[j]);
				adj[primes[j]].pb(primes[i]);
			}
		}
	}
}

void bfs(int src){
	vis[src] ++;
	dist[src] = 0;
	queue<int> q;
	q.push(src);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v: adj[u]){
			if(!vis[v]){
				vis[v] ++;
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
	}
}
int main() 
{
	FIO
	createGraph();
	T(){
		vis.clear();
		dist.clear();
		int x, y;
		cin >> x >> y;
		bfs(x);
		if(!dist[y] and x!=y){
			cout << "Impossible\n";
		}
		else{
			cout << dist[y] << "\n";
		}
	}
	return 0;
}