#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int N = 1e3 + 5;
const int maxN = log2(N)+1;

vector<int> adj[N];
int LCA[N][maxN];
int level[N];

void _init_(){
	for(int i=0; i<N; i++){
		adj[i].clear();
		level[N] = 0;
		for(int j=0; j<maxN; j++){
			LCA[i][j] = -1;
		}
	}
}

void dfs(int src, int par=-1, int lvl = 0){
	level[src] = lvl;
	LCA[src][0] = par;
	for(int i=1; i<maxN; i++){
		if(LCA[src][i-1] != -1){
			LCA[src][i] = LCA[LCA[src][i-1]][i-1];
		}
	}
	for(auto child: adj[src]){
		if(child != par){
			dfs(child, src, lvl+1);
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
	
	for(int i=maxN-1; i>=0; i--){
		if(LCA[a][i] != -1 and LCA[a][i] != LCA[b][i]){
			a = LCA[a][i];
			b = LCA[b][i];
		}
	}
	return LCA[a][0];
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	for(int tc=1; tc<=t; tc++){
		_init_();
		int n, m, q, x;
		cin >> n;
		
		for(int i=1; i<=n; i++){
			cin >> m;
			if(m == 0) continue;
			for(int j=0; j<m; j++){
				cin >> x;
				adj[i].pb(x);
				adj[x].pb(i);
			}
		}
		dfs(1, -1, 0);
		cout << "Case " << tc << ":\n";
		cin >> q;
		while(q--){
			int a, b;
			cin >> a >> b;
			cout << getLCA(a, b) << "\n";
		}
	}
	return 0;
}