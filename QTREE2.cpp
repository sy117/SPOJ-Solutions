#include <bits/stdc++.h>
#define pb push_back

using namespace std;

typedef long long int LL;
typedef pair<int, int> PI;

const int INF = 1e9;
const int N = 1e4 + 5;
const int M = log2(N)+1;

vector<PI> adj[N];
int LCA[N][M];
int level[N], dist[N];

void _init_(){
	for(int i=0; i<N; i++){
		adj[i].clear();
		level[N] = 0;
		dist[N] = 0;
		for(int j=0; j<M; j++){
			LCA[i][j] = -1;
		}
	}
}

void dfs(int src, int par, int d, int lvl){
	level[src] = lvl;
	dist[src] = ((par==-1)? 0: dist[par]) + d;
	LCA[src][0] = par;
	for(int i=1; i<M; i++){
		if(LCA[src][i-1] != -1){
			LCA[src][i] = LCA[LCA[src][i-1]][i-1];
		}
	}
	for(auto p: adj[src]){
		if(p.first != par){
			dfs(p.first, src, p.second, lvl+1);
		}
	}
}

int getLCA(int a, int b){
	int diff = level[b] - level[a];
	if(diff < 0){
		diff = -diff;
		swap(a, b);
	}
	while(diff > 0){
		int lift = log2(diff);
		b = LCA[b][lift];
		diff -= (1<<lift);
	}
	if(a == b) return a;
	
	for(int i=M-1; i>=0; i--){
		if(LCA[a][i] != -1 and LCA[a][i] != LCA[b][i]){
			a = LCA[a][i];
			b = LCA[b][i];
		}
	}
	return LCA[a][0];
}

int getKthPar(int x, int k){
	while(k > 0){
		int lift = log2(k);
		x = LCA[x][lift];
		k -= (1<<lift);
	}
	return x;
}
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		_init_();
		int n;
		cin >> n;
		int x, y, w;
		for(int i=1; i<n; i++){
			cin >> x >> y >> w;
			adj[x].pb({y, w});
			adj[y].pb({x, w});
		}
		dfs(1, -1, 0, 0);
		int a, b, k;
		string query;
		for(int i=0; i<1e6; i++){
			cin >> query;
			if(query == "DONE"){
				break;
			}
			else if(query == "DIST"){
				cin >> a >> b;
				int lca = getLCA(a, b);
				int res = dist[a] + dist[b] - 2*dist[lca];
				cout << res << "\n";
			}
			else{
				cin >> a >> b >> k;
				int res = 0, lca, d1, d2;
				lca = getLCA(a, b);
				d1 = level[a] - level[lca];
				d2 = level[b] - level[lca];
				if(k==d1+1){
					res = lca;
				}
				else if(k < d1+1){
					res = getKthPar(a, k-1);
				}
				else if(k > d1+1){
					res = getKthPar(b, (d1+d2+1-k));
				}
				cout << res << "\n";
			}
		}
	}
	return 0;
}