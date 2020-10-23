#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef pair<int, int> PI;
const int N = 705;

vector<int> adj[N];
vector<PI> bridges;
bool vis[N];
int in[N];
int lo[N];
int timer;

void _init_(int n){
	timer = 0;
	bridges.clear();
	for(int i=0; i<=n; i++){
		adj[i].clear();
		vis[i] = false;
		in[i] = lo[i] = -1;
	}
}

void dfs(int src, int par){
	vis[src] = true;
	in[src] = lo[src] = timer++;
	for(auto to: adj[src]){
		if(to==par){
			continue;
		}
		if(vis[to]){
			lo[src] = min(lo[src], in[to]);
		}
		else{
			dfs(to, src);
			lo[src] = min(lo[src], lo[to]);
			if(lo[to] > in[src]){
				bridges.pb({min(src, to), max(src, to)});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc;
	cin >>tc;
	for(int i=1; i<=tc; i++){
		int n, m;
		cin >>n >> m;
		_init_(n);
		int u, v;
		for(int j=0; j<m; j++){
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs(1, -1);
		cout << "Caso #" << i << "\n";
		if(bridges.size() == 0){
			cout << "Sin bloqueos\n";
		}
		else{
			sort(bridges.begin(), bridges.end());
			cout << bridges.size() << "\n";
			for(auto p: bridges){
				cout << p.first << " " << p.second << "\n";
			}
		}
	}
	return 0;
}