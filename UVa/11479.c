#include<stdio.h>

int main()

{
    int T,i;

    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        long long int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);

        if(a+b<=c || b+c<=a || a+c<=b)
        {
            printf("Case %d: Invalid\n",i);
        }
        else if(a==b && b==c && c==a)
        {
            printf("Case %d: Equilateral\n",i);
        }
        else if(a==b || b==c || a==c)
        {
            printf("Case %d: Isosceles\n",i);
        }
        else if(a!=b && b!=c && c!=a)
        {
            printf("Case %d: Scalene\n",i);
        }

    }

    return 0;
}


