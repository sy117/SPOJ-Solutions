#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

vector<bool> prime(N, true);
vector<int> ans(N, 0);

void sieve(){
	prime[0] = prime[1] = false;
	
	for(int i=2; i*i<N; i++){
		if(prime[i]){
			for(int j=i*i; j<N; j+=i){
				prime[j] = false;
			}
		}
	}
}

int revNum(int x){
	int res=0, rem;
	while(x>0){
		rem = x%10;
		if(rem == 0){
			return -1;
		}
		res = (res*10) + rem;
		x /= 10;
	}
	return res;
}

void preCal(){
	sieve();
	for(int i=2; i<N; i++){
		if(prime[i]){
			int rev = revNum(i);
			while(rev > 0 and prime[revNum(rev)]){
				rev /= 10;
			}
			if(rev == 0){
				ans[i] = 1;
			}
		}
		ans[i] += ans[i-1];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	preCal();
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		cout << ans[x] << "\n";
	}
	return 0;
}