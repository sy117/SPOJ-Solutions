#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef pair<int, int> PI;
typedef pair<LL, LL> PL;

const int N = 1e6 + 10;
vector<LL> primes;

void sieve(){
	vector<int> vec(N, true);
	vec[0] = vec[1] = false;
	for(int i=2; i*i<N; i++){
		if(vec[i]){
			for(int j=i*i; j<N; j+=i){
				vec[j] = false;
			}
		}
	}
	primes.push_back(2);
	for(int i=3; i<N; i+=2){
		if(vec[i]){
			primes.push_back((LL)i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	sieve();
	
	int t;
	cin >> t;
	while(t--){
		LL N;
		cin >> N;
		LL base = N, maxc = 0;
		for(auto p: primes){
			if(p*p <= N){
				LL cnt = 0;
				if(N%p == 0){
					while(N%p == 0){
						N /= p;
						cnt++;
					}
				}
				if(cnt > maxc){
					maxc = cnt;
					base = p;
				}
			}
			else{
				break;
			}
			
		}
		cout << base << "\n";
	}
	return 0;
}