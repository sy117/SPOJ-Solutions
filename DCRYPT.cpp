#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[100001];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int key,i,j,k;
		cin>>key;
		cin>>str;
		k=strlen(str);
		if(key>=0 && key<=25)
		{
			for(i=0;i<k;i++)
			{
				if(str[i]==46)
				{
					str[i]=32;
				}
				else
				{
				  if(str[i]>96)
				  {
				  	if(str[i]+key>122)
				  	  str[i]=str[i]+key-26;
				  	  else
				  	  str[i]+=key;
				  }
				  else
				  {
				  	if(str[i]+key>90)
				  	str[i]=str[i]+key-26;
				  	else
				  	str[i]+=key;
				  }
				}
				
			}
			printf("%s\n",str);
		}
		else if(key>=26 && key<=51)
		{
			key=key-26;
			for(i=0;i<k;i++)
			{
				if(str[i]==46)
				{
					str[i]=32;
				}
				else
					{
				    if(str[i]>96)
				  {
				  	if(str[i]+key>122)
				  	  str[i]=str[i]+key-26-32;
				  	  else
				  	  str[i]+=key-32;
				  }
				  else
				  {
				  	if(str[i]+key>90)
				  	str[i]=str[i]+key-26+32;
				  	else
				  	str[i]+=key+32;
				  }
				}
			}
			printf("%s\n",str);
		}
		
	}
	
	return 0;
}