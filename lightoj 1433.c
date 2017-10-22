#include<stdio.h>
#include<math.h>

int main()

{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        int a,b,c,d,e,f;
        scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);

        double radius= sqrt(pow(a-c,2)+pow(b-d,2));

        double length= sqrt(pow(c-e,2)+pow(d-f,2));

        double length1= 1- 0.5*pow(length/radius,2);

        double angle= acos(length1);

        printf("Case %d: %lf\n",i,radius*angle);

    }

    return 0;
}
