#include<stdio.h>

int main()

{
    long long int T,i;
    scanf("%lld",&T);

    for(i=1;i<=T;i++)
    {
        long long int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);

        if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a) printf("Case %lld: yes\n",i);
        else printf("Case %lld: no\n",i);
    }

    return 0;
}
