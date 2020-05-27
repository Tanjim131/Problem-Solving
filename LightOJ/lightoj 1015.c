#include<stdio.h>

int main()

{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)
    {
        int N;
        scanf("%d",&N);

        int a[N];

        int j;

        for(j=0;j<N;j++)
        {
            scanf("%d",&a[j]);
        }

        int dust=0;

        for(j=0;j<N;j++)
        {
            if(a[j]>=0)
            {
                dust+=a[j];
            }
        }

        printf("Case %d: %d\n",i,dust);
    }

    return 0;
}
