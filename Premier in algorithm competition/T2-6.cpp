#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	double sum=0;
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		sum+=1./i;
	}
	printf("%.3lf",sum);
}
