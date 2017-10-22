#include<stdio.h>

int main()

{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        double v1,v2,v3,a1,a2;
        scanf("%lf %lf %lf %lf %lf",&v1,&v2,&v3,&a1,&a2);

        double t1=v1/a1,t2=v2/a2;

        double d=(v1*t1-(0.5*a1*t1*t1))+(v2*t2-(0.5*a2*t2*t2));

        double time= (t1>t2)?t1:t2;

        double distance= v3*time;

        printf("Case %d: %0.9lf %0.9lf\n",i,d,distance);
    }

    return 0;
}
