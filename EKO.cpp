#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

LL woodAmount(LL arr[], LL N, LL h){
	LL  val = 0;
	for(int i=0; i<N; i++){
		if(arr[i] > h)
		val += (arr[i] - h);
	}
	return val;
}

int main() {
	LL N, W;
	cin >> N >> W;
	LL arr[N], maxHeight = 0;
	for(int i=0; i<N; i++){
		cin >> arr[i];
		maxHeight = max(maxHeight, arr[i]);
	}
	LL lo, hi, ans = 0;
	
	lo = 0, hi = maxHeight;
	while(lo <= hi){
		LL mid = lo + (hi-lo)/2;
		if(woodAmount(arr, N, mid) >= W){
			ans = mid;
			lo = mid+1;
		}
		else{
			hi = mid-1;
		}
	}
	cout << ans << "\n";
	return 0;
}