#include <stdio.h>
#include <string.h>

#define u8	unsigned char

int fun1(int *p){
	int a1;
	
	a1 = --(*p);
	
	return a1 > 0;
}

int fun2(int *p){
	int h1;
	
	h1 = (*p) + 1;
	*p = h1;
	
	if(h1 < 8) return 12;
	else return 0;
}

int fun3(int *x){
	int v1;
	
	v1 = --(*x);
	
	return v1 > 0;
}

int fun4(int *p){
	int a1;
	
	a1 = ++(*p);
	
	if(a1 < 8) return 0x32;
	else return 0;
}

int main(){
	u8 m[65] = {
		0x20, 0x20, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A,
		0x2A, 0x20, 0x20, 0x20, 0x2A, 0x20, 0x20, 0x2A,
		0x2A, 0x2A, 0x2A, 0x20, 0x2A, 0x20, 0x2A, 0x2A,
		0x2A, 0x2A, 0x20, 0x20, 0x2A, 0x20, 0x2A, 0x2A, 
		0x2A, 0x20, 0x20, 0x2A, 0x23, 0x20, 0x20, 0x2A, 
		0x2A, 0x2A, 0x20, 0x2A, 0x2A, 0x2A, 0x20, 0x2A, 
		0x2A, 0x2A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2A, 
		0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A,
		0x00
	};
	char s[100];
	long long a = 0; // int a[2] = {0};
	int a1;
	char a2;
	char a3;
	int a4;
	
	puts("Input flag:");
	scanf("%s", s);
	a1 = 0;
	if(strlen(s) == 022){
		while(1){
			a2 = s[a1];
			if(a2 > 78){
				a3 = a2;
				if(a3 == 79){
					a4 = fun1((int *)&a + 1); // a[1]--;
				}
				if(a3 == 111){
					a4 = fun2((int *)&a + 1); // a[1]++;
				}
			}else{
				a3 = a2;
				if(a3 == 46){
					a4 = fun3((int *)&a); // a[0]--;
				}
				if(a3 == 48){
					a4 = fun4((int *)&a); // a[0]++;
				}
			}
			if(!a4) break;
			if(++a1 >= 0x12){
					m		a[0]	* 8		+		a[1]		
				if(*(m + (*(int *)&a * 8) + *((int *)&a + 1)) != '#'){		// m[a[0]][a[1]]
					break;
				}else{
					puts("Congratulations\r\n");
					return 0;
				}
			}
		}
	}
	
	printf("Wrong flag!\r\n");
	
	return 0;
} 
