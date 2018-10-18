#include<bits/stdc++.h>
int main()
{
    double n,price=95,total;
    std::cin>>n;;
    if(n>=300*1.0/95) {total=price*n*0.85;}
    else {total=price*n;}
    std::cout<<total;
    return 0;
}
