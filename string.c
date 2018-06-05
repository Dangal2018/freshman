#include<stdio.h>
int main()
{
	int i;
    char str1[1000],str2[1000];
    printf("please input a string\n");
    gets(str1);
    for(i=0;str1[i]!='\0';i++)
    {
    	if(str1[i]>='a'&&str1[i]<='z')
    	{
    		str1[i]-=4;
		}
		if(str1[i]>='A'&&str1[i]<='Z')
		{
			str1[i]+=3;
		}
		str2[i]=str1[i];
		}
		printf("the string after change:\n");
		puts(str2);
	return 0;
}
