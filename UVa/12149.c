#include<stdio.h>

int main()

{
    int n;

    while(1==scanf("%d",&n))
    {
        if(n==0)
        {
            break;
        }
        else
        {
            printf("%d\n", (n*(n+1)*(2*n+1))/6);
        }
    }

    return 0;

}
