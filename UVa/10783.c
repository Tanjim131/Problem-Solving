#include<stdio.h>

int main()

{
    int T,i,j,sum;

    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        int a,b;
        scanf("%d\n",&a);
        scanf("%d",&b);

        sum=0;

        j=a;
        while(j<=b)
        {
            if(j%2!=0)
            {
                sum+=j;
            }
            j++;
        }

        printf("Case %d: %d\n",i,sum);
    }

    return 0;
}
