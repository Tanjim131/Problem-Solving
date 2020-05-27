#include<stdio.h>
#include<stdlib.h>

int main()

{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        int n,k;
        scanf("%d",&n);

        k=(((((((n*567)/9)+7492)*235)/47)-498)%100)/10;

        printf("%d\n",abs(k));

    }

    return 0;
}
