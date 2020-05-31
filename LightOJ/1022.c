#include<stdio.h>
#include<math.h>
#define pi 2*acos(0.0)
 
int main()
 
{
    int T,i;
    scanf("%d",&T);
 
    for(i=1;i<=T;i++)
 
    {
        double r;
        scanf("%lf",&r);
        printf("Case %d: %0.2lf\n",i,(((r*r)-(pi*r*r)/4)*4));
    }
 
    return 0;
}