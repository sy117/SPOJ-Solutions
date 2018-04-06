#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll gcd(ll a, ll b)
{
     if (b==0)
        return a;
    else
	return gcd(b,a%b);
}
int main()
{
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a,b,i,k,d,m,ans;
		char s[252];
		scanf("%lld%s",&a,s);
		k = strlen(s);
		if(a==0)
		printf("%s\n",s);
		else if(k==1 && s[0]=='0')
		printf("%lld\n",a);
		else
		{
		    b=0;
		    for(i=0;i<k;i++)
		    {
			   m=10*b+(s[i]-48);
			   b=m%a;
		    }
		    ans = gcd(a,b);
		    printf("%lld\n",ans);
		}
	}
	return 0;
}