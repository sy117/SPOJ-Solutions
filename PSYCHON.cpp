#include <bits/stdc++.h>
using namespace std;


bool isPsycho(int x){
	int even = 0, odd = 0;
	for(int p=2; p*p <= x; p++){
		int cnt = 0;
		if(x%p == 0){
			while(x%p == 0){
				cnt++;
				x /= p;
			}
		}
		if(cnt > 0){
			if(cnt&1) odd++;
			else even++;
		}
	}
	if(x>1) odd++;
	return (even > odd);
}

int main() {
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >>x;
		if(isPsycho(x)){
			cout << "Psycho Number\n";
		}
		else{
			cout << "Ordinary Number\n";
		}
	}
	return 0;
}