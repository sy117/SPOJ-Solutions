#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n;
	multiset<LL> st;
	LL ans = 0;
	for(int i=0; i<n; i++){
		cin >> k;
		LL x;
		for(int j=0; j<k; j++){
			cin >> x;
			st.insert(x);
		}
		auto it1 = st.begin();
		auto it2 = st.end(); it2--;
		ans += abs(*it1 - *it2);
		st.erase(it1);
		st.erase(it2);
	}
	cout << ans << "\n";
	return 0;
}