#include<stdio.h>

int main()

{
    int a,b,c;

    while(3==scanf("%d %d %d",&a,&b,&c))

    {

        if(a==0 && b==0 && c==0)

        {
            break;
        }
        else if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)

        {
            printf("right\n");
        }
        else
        {
            printf("wrong\n");
        }

    }


    return 0;
}
