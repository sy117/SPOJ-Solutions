#include <bits/stdc++.h>
using namespace std;

bool okk(string st,int num)
{
	int res=0;
	for(int i=0;i<st.length();i++)
	{
		res = res*10 + (st[i]-'0');
		res%=num;
	}
	return (res==0);
}
string fun(int x)
{
	string s;
	queue<string> q;
	q.push("1");
	while(!q.empty())
	{
		s = q.front();
		q.pop();
		if(okk(s, x))
		{
			return s;
		}
		else
		{
			q.push(s+"0");
			q.push(s+"1");
		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string ans = fun(n);
		cout<<ans<<"\n";
	}
	return 0;
}