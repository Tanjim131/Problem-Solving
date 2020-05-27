#include<stdio.h>
#include<math.h>

int main()

{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        double a,b,c,d;

        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);

        double h=sqrt(b*b-(((((a-c)*(a-c))-((d*d)-(b*b)))/(2*(a-c)))*((((a-c)*(a-c))-((d*d)-(b*b)))/(2*(a-c)))));

        printf("Case %d: %0.10lf\n",i,0.5*(a+c)*h);
    }

    return 0;
}
