#include <stdio.h>
int main()
{
    int i,p = 1;
    double quarter_pi,temp_i;
    for( i = 1;;i++){
        temp_i = 1.0/i;
       quarter_pi+= p*temp_i;
        p = -p;
        if(temp_i < 10e-6)
            break;
    }
    printf("%lf\n",quarter_pi);
    return 0;
}
