#include<stdio.h>
#include<stdlib.h>

int main()

{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        int C,F;
        scanf("%d %d",&C,&F);

        double C2= (C+(5.0/9)*F);

        if(C2<0)
        {
            C2=-C2;
        }

        printf("Case %d: %0.2lf\n",i,C2);
    }

    return 0;

}
