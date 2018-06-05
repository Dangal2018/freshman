#include<stdio.h>
#define N 10
int average()
{ 
	int i,a[N],sum=0;
	float average=0;
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	sum=sum+a[i];
	average=1.*sum/N;}
	printf("sum: %d average: %.1f ",sum,average);
}
int main()
{
	int a[N];
	average();
	return 0;
}
