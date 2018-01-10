#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int a[n][m],dp[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<m;i++){
			dp[0][i]=a[0][i];
		}
		for(int i=1;i<n;i++){
			for(int j=0;j<m;j++){
				if(j==0){
					dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i-1][j+1]);
				}
				else if(j==m-1){
					dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
				}
				else{
					dp[i][j]=a[i][j]+max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]));
				}
			}
		}
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(dp[i][j]>ans)
				ans=dp[i][j];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}