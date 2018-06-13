#include<stdio.h>
int main()
{
    const int N=30;/*（这里的N可以是任何正整数（N为学生数） N can be any positive integer（N means the number of student））*/
    int a[N],i,j,k,m=0,t;
    /*输入所有学生成绩（input all of students' grade*/ 
	do{
		printf("please input student's point a[%d]=",i);
		scanf("%d",&a[i]);
		i++;
	  }
	while(a[i-1]>0&&i<N);
  /*从高到低排序（grade from high to low）*/
	k=i-2;
	for(i=0;i<k;i++)
{
		for(j=i+1;j<k+1;j++)
		if(a[i]>a[j]){
			t=a[i];a[i]=a[j];a[j]=t;
		}
		if(a[i]<60){		
		printf("the fail point:a[%d]=%d\n",i,a[i]);
		m++;
	}		
}
    printf("The number of failed students is:%d\n",m);
    printf("the highest grade in the class is:%d\n",a[k]);
    printf("the lowest grade in the class is:%d\n",a[0]);
	  return 0;
} 
