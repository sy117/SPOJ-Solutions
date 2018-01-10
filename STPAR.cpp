#include <bits/stdc++.h>
using namespace std;

int main() 
{
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
		  break;
		int a[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		stack<int> st;
		int flag,curr=1;
		for(int i=0;i<n;)
		{
			if(a[i]==curr)
			{
				curr++;
				i++;
			}
			else
			{
				if(st.empty())
				{
					st.push(a[i]);
					i++;
				}
				else
				{
					if(st.top()==curr)
					{
						st.pop();
						curr++;
					}
					else
					{
						st.push(a[i]);
						i++;
					}
				}
			}
		}
		while(!st.empty())
		{
			if(st.top()==curr)
			{
				st.pop();
				curr++;
			}
			else
			{
				break;
			}
		}
		if(curr==n+1)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}