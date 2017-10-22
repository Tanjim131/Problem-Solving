#include<stdio.h>

int main()

{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        int a,b,time=0;

        scanf("%d %d",&a,&b);

        if(a<=b)
        {

            while(b>a)
            {
                b--;
                time+=4;
            }

            time+=11;

            while(a>0)
            {
                time+=4;
                a--;
            }

            time+=8;

            printf("Case %d: %d\n",i,time);
        }


    else
    {
        while(a>b)
        {
            b++;
            time+=4;
        }


        time+=11;

        while(a>0)
            {
                time+=4;
                a--;
            }

        time+=8;

        printf("Case %d: %d\n",i,time);
    }

    }

    return 0;
}
