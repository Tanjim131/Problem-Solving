#include<stdio.h>
#include<math.h>

int main()

{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        double R1,R2,R3;
        scanf("%lf %lf %lf",&R1,&R2,&R3);

        double a=R2+R3,b=R1+R3,c=R1+R2;

        double A= acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c));
        double B= acos((pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c));
        double C= acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b));

        double area1= (A/2)*R1*R1, area2=(B/2)*R2*R2, area3=(C/2)*R3*R3;

        double triangle_area= 0.5*b*c*sin(A);

        printf("Case %d: %0.9lf\n",i,triangle_area-(area1+area2+area3));
    }

    return 0;
}
