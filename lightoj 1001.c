#include<stdio.h>

int main()

{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        int n;
        scanf("%d",&n);

        if(n>10) printf("%d %d\n",10,n-10);

        else printf("%d 0\n",n);

    }


    return 0;
}
