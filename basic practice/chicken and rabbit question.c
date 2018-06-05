#include<stdio.h>
int main()
{
int t,l;        /* （鸡兔总数和他们腿的总数）t=total number l=leg total numbers  */
    printf("please input total number and leg total number:(form:num1 num2)\n");
    scanf("%d %d",&t,&l);
if(l<=4*t&&l%2==0&&t>0&&l>0)/* （鸡兔同笼问题有解的先决条件）condition of possible */
{
	printf("chicken:%d rabbit:%d\n",2*t-l/2,l/2-t);
}
else
    printf("impossible\n");
    return 0;
}
