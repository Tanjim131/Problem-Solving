#include<stdio.h>

int main()


{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

        int N;
        scanf("%d",&N);

        printf("Case %d:\n",i);

        int j;

        for(j=1;j<=N;j++)
        {
            int a,b;
            scanf("%d %d",&a,&b);

            if((a>x1 && a<x2) && (b>y1 && b<y2)) printf("Yes\n");

            else printf("No\n");
        }
    }

    return 0;
}
