#include<stdio.h>

int divisor(int n)
{
    int i,counter=0;
    for(i=1;i*i<=n;i++)
    {
        if(!(n%i)) counter++;
    }
    int y=sqrt(n);

    if(n==y*y) return (2*counter)-1;
    else return 2*counter;
}

int main()

{
    int ara[1001];

    int i,j,t=2,max=2;

    for(i=1;i<1001;i++)
    {
        ara[i]=divisor(i);
        if(max<divisor(i)) max=divisor(i);
    }

    int ara1[1001];

    ara1[1]=1;

    for(i=2;i<=max;i++)
    {
        for(j=1000;j>1;j--)
        {
            if(ara[j]==i) ara1[t++]=j;
        }
    }

    int T,k=0;
    scanf("%d",&T);

    while(T--)
    {
        int x;
        scanf("%d",&x);

        printf("Case %d: %d\n",++k,ara1[x]);
    }
    return 0;
}







