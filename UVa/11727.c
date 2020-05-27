#include<stdio.h>

int main()

{
    int T,i;

    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        int a,b,c;

        scanf("%d %d %d",&a,&b,&c);

        int ara[3]={a,b,c};

        int j,k,t;

        for(j=0;j<3;j++)
        {
            for(k=j+1;k<3;k++)
            {
                if(ara[j]>ara[k])
                {
                    t=ara[k];
                    ara[k]=ara[j];
                    ara[j]=t;
                }
            }
        }

        printf("Case %d: %d\n",i,ara[1]);
    }

    return 0;


}
