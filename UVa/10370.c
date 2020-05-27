#include<stdio.h>

int main()

{
    int T,i;

    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        int N;
        scanf("%d",&N);

        int ara[N];

        int j;

        for(j=0;j<N;j++)
        {
            scanf("%d",&ara[j]);
        }

        int sum=0;

        for(j=0;j<N;j++)
        {
            sum+=ara[j];
        }

        double avg= sum/N;

        double count=0; //eikhane double data type na dile kaj hoy na ken???

        for(j=0;j<N;j++)
        {
            if(ara[j]>avg)
            {
                count++;
            }
        }

        double p;

        p= (count*100)/N;

        printf("%0.3lf%%\n",p);


    }

    return 0;
}
