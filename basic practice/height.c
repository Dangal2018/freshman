#include<stdio.h>
#include<math.h>
int main()
{
float fh,mh,th,rh;                                    //fh=father's height; mh=mother's height; th=theoretic height; rh=real height;
char gender,m,f;                                      //m=male; f=female;
printf("please input male(as m) or female (as f)?\n");
scanf("%c",&gender);
printf("please input your real height:\n");
scanf("%f",&rh);
printf("please input parent's height(form:num1 num2):\n");
scanf("%f %f",&fh,&mh);
if(gender='m'){
	th=(fh+mh)*1.08/2;
	printf("%.2f\n",th);
}
else{
	th=(0.923*fh+mh)/2;
	printf("%.2f\n",th);
}
if(abs(th-rh)<=3){
	printf("Conforming to the conclusion\n");
}
else{
printf("Not conforming to the conclusion\n");
} 
return 0;
}
