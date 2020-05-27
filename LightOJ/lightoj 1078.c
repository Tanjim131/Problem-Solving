#include<stdio.h>
#include<string.h>

int main()

{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        int a,b;
        scanf("%d %d",&a,&b);

        char number[1000];

        int j=0,t=0,d,flag=0,length=0;

        while(flag!=1)
        {

            d=t;

            number[j]=b+'0';

            printf("%c",number[j]);
            //printf("\n");

            length=strlen(number);

            d=((d*10)+(number[j]-'0'))%a;

            printf("%d\n",d);

            t=d;

            printf("%d\n",t);

            if(d==0)
            {
                flag=1;
            }

            j++;

        }

        printf("Case %d: %d\n",i,length);
    }

    return 0;
}
