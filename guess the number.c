/* */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
int r,n,t;
srand(time(0));
r=rand()%100+1;
for(t=1;t<=10;t++)
{
	printf("please input n,range for a is[1,100]\n");
	scanf("%d",&n);
	if(n<=0||n>100)
	{
		printf("out of range,please input a number in range");
	    break; 
	}
	if(n!=r)
	{
		printf("wrong answer,you have only %d chance(s)\n",10-t);
	}
	if(n>r)
	{
		printf("bigger than correct answer\n");
		continue;
	}
	if(n<r)
	{
		printf("smaller than correct answer\n");
		continue;
	}
	if(n==r)
	{
		printf("you guess %d time(s),",t);
		printf("you got it!\n");
		break;
	}
}
    if(t==11)
		printf("the correct answer is %d\n",r);
        return 0;
}
