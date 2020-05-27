#include<stdio.h>
#include<string.h>

int main()

{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        char number[1000];
        scanf("%s",&number);

        long long int num;
        scanf("%lld",&num);

        long long int length=strlen(number);

        long long int j,vagsesh=0;

        if(number[0]=='-')
        {
            for(j=1;j<length;j++)
            {
                vagsesh=((vagsesh*10)+(number[j]-'0'))%num;
            }

            if(vagsesh==0)
            {
                printf("Case %d: divisible\n",i);
            }
            else
            {
                printf("Case %d: not divisible\n",i);
            }
        }
        else
        {
            for(j=0;j<length;j++)
            {
                vagsesh=((vagsesh*10)+(number[j]-'0'))%num;
            }

            if(vagsesh==0)
            {
                printf("Case %d: divisible\n",i);
            }
            else
            {
                printf("Case %d: not divisible\n",i);
            }
        }
    }

    return 0;
}
