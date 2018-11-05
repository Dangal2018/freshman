#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main()
{
	cin>>a>>b>>c;
	for(int i=10;i<=100;i++)
	{
		if(i%3==a&&i%5==b&&i%7==6)
		{
			cout<<i;
		break;
		}
		else
		{
			cout<<"No answer";
			break;
		}
	}
	return 0;
}
