#include<stdio.h>
#include<stdlib.h>

int main()

{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        int a,b,c,d,e,f;
        scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);

        int area= (a*d+c*f+b*e)-(b*c+d*e+a*f);

        printf("Case %d: %d %d %d\n",i,(a+e-c),(b+f-d),abs(area));
    }

    return 0;
}
