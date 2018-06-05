#include<stdio.h>
int statistics()
{
	int letter=0,number=0,space=0,others=0,i;
	char str[100];
	gets(str);	
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>64&&str[i]<123)
		letter++;
		else if(str[i]>47&&str[i]<58)
		number++;
		else if(str[i]==32)
		space++;
		else
		others++;	
	}
	printf("letter: %d number: %d space: %d others: %d",letter,number,space,others);
}
int main()
{
    statistics(); 
	return 0;
}
