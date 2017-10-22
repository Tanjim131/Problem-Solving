#include<stdio.h>

int main()

{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        int a,b;
        scanf("%d %d",&a,&b);

        printf("Case %d: %d\n",i,a+b);

    }

    return 0;
}
