#include<stdio.h>

int main()

{
    long long int T,i=0;
    scanf("%d",&T);

    while(T--)
    {
        long long int a,b;

        scanf("%lld %lld",&a,&b);

        printf("Case %lld: %lld\n",++i,(a*b)>>1);
    }

    return 0;
}
