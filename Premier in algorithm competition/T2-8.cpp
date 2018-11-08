#include<bits/stdc++.h>
using namespace std;
long long int m,n;
double sum=0;
int main()
{
	cin>>n>>m;
	for(int i=n;i<=m;i++)
	{
		sum+=1./i/i;
	}
	printf("%.5lf",sum);
	return 0; 
}
//trap:if you write(sum+=1/(i*i),maybe i*i isn't belong to the range of INT_64)
