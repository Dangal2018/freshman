#include<bits/stdc++.h>
int main()
{
    int a,b,c;
    std::cin>>a>>b>>c;
    if(a+b>=c&&b+c>=a&&c+a>=b&&(a*a==b*b+c*c||b*b==a*a+c*c||c*c==a*a+b*b))
    std::cout<<"yes";
    else std::cout<<"no";
    return 0;
}
