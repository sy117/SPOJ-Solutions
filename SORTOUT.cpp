#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<string> v;
	int n,q,k;
	cin>>n>>q;
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		v.push_back(s);
	}
	sort(v.begin(),v.end());
	while(q--)
	{
		cin>>s;
		k=upper_bound(v.begin(),v.end(),s)-v.begin();
		cout<<k<<"\n";
	}
	return 0;
}