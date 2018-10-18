//Wrong code
#include <stdio.h>

int main(){

	double i;

	for(i = 0.0; i  = 10.0; i += 0.1)

	printf("%.1f\n",i);

	

	return 0;

}
//Correct code

#include <stdio.h>

int main(){

	double i;

	for(i = 0.0; i -10 < 0.0; i += 0.1)

	printf("%.1f\n",i);

	

	return 0;

}
