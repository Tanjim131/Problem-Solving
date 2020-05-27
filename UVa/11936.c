#include<stdio.h>

int main()

{
    int t,i;

    scanf("%d",&t);

    for(i=1;i<=t;i++)

    {
        int a,b,c;

        scanf("%d %d %d",&a,&b,&c);

        if(a+b<=c || b+c<=a || a+c<=b)
        {
            printf("Wrong!!\n");
        }
        else
        {
            printf("OK\n");
        }
    }

    return 0;
}
