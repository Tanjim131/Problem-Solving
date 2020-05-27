#include<stdio.h>
#define pi acos(-1)

int main()

{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        double L;
        scanf("%lf",&L);

        double area_red,area_green;


        double W= (L*3)/5.0;
        double r= L/5.0;

        area_red=pi*r*r;
        area_green= (L*W)-(area_red);

        printf("%0.2lf %0.2lf\n",area_red,area_green);


    }

    return 0;
}