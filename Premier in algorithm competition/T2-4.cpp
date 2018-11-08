#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<i; j++)
			cout<<" ";
		int count=2*(n-i+1)-1;
		while(count>0)
		{
			cout<<"#";
			count--;
		}
		cout<<endl;
	}
}
