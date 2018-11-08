#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int N,a[1000],m,cnt=0;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>a[i];
	}
	cin>>m;
	for(int i=0;i<N;i++)
	{
		if(a[i]<m) cnt++;
	}
	cout<<cnt;
}
