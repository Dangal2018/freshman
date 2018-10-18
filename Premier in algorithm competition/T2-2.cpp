#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,c;
  for(a=1;a<=9;a++){
  	for(b=0;b<=9;b++){
  		for(c=0;c<=9;c++){
				if(100*a+10*b+c==a*a*a+b*b*b+c*c*c)
				cout<<100*a+10*b+c<<endl;  			
		  }
	  }
  }
  return 0;
}
