#include<stdio.h>

long long int dp[100];

long long int F(int n)
{
    if(n==0) return 0;
    else if(n==1) return 1;

    if(dp[n]!=-1) return dp[n];

    else
    {
        dp[n]=F(n-1)+F(n-2);
    }

    return dp[n];
}

int main()

{
    int n;

    int i;

    for(i=0;i<100;i++) dp[i]=-1;

    while(1==scanf("%d",&n))
    {
        if(!n) break;

        else
        {
            printf("%lld\n",F(n+1));
        }
    }

    return 0;
}
