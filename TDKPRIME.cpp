    #include <bits/stdc++.h>
    #define MAX 100000001
    using namespace std;
     
    int prime[MAX];
    bool v[MAX];
    void sieve()
    {
    	memset(v,true,sizeof(v));
    	v[0]=v[1]=false;
    	for(int i=2;i*i<MAX;i++)
    	{
    		if(v[i])
    		{
    			for(int j=i*i;j<MAX;j+=i)
    			{
    				v[j]=false;
    			}
    		}
    	}
    	int k=1;
    	prime[0]=0;
    	for(int i=2;i<MAX;i++)
    	{
    		if(v[i])
    		{
    			prime[k++]=i;
    		}
    	}
    }
    int main() 
    {
    	sieve();
    	int q;
    	scanf("%d",&q);
    	for(int i=0;i<q;i++)
    	{
    		int n;
    		scanf("%d",&n);
    		cout<<prime[n]<<"\n";
    	}
    	return 0;
    } 