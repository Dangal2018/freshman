#include<stdio.h>
int main()
{
int a,b,c;
scanf("%d",&a);
c=a;
for(;c>0&&a>0;){
c=a;
b=a%10;
printf("%d ",b);
a/=10;}
return 0;
}
