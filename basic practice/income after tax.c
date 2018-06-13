#include<stdio.h>
int main()
{
int income,tax;
    printf("your income:\n");
    scanf("%d",&income);
    if(income>=0&&income<3500)
    {
    	printf("tax:0");
	}
	else if(income>=3500&&income<5000)
	{
		tax=0.03*(income-3500);
	    printf("tax:%d",tax);
	}
    else if(income>=5000&&income<8000)
    {
    	tax=0.1*(income-3500)-105;
    	printf("tax:%d",tax);
	}
	else if(income>=8000&&income<12500)
	{
		tax=0.2*(income-3500)-555;
		printf("tax:%d",tax);
	}
	else if(income>=12500&&income<35000)
	{
		tax=0.25*(income-3500)*1005;
		printf("tax:%d",tax);
	}
	else if(income>=38500&&income<58500)
	{
		tax=0.3*(income-3500)-2755;
		printf("tax:%d",tax);
	}
	else if(income>=58500&&income<83500)
	{
		tax=0.35*(income-3500)-5505;
		printf("tax:%d",tax);
	}
	else{
		tax=0.45*(income-3500)-13505;
		printf("tax:%d",tax);
	}	
return 0;
}
