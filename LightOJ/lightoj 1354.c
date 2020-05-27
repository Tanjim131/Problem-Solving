#include<stdio.h>
#include<math.h>

int binary_decimal(int n)

{
    int decimal=0, i=0, rem;
    while (n!=0)
    {
        rem=n%10;
        n/=10;
        decimal+=rem*pow(2,i);
        i++;
    }
    return decimal;
}

int main()

{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        int decimal[4];
        int binary[4];

        scanf("%d.%d.%d.%d",&decimal[0],&decimal[1],&decimal[2],&decimal[3]);
        scanf("%d.%d.%d.%d",&binary[0],&binary[1],&binary[2],&binary[3]);

        int number[4];

        int j;

        for(j=0;j<4;j++)
        {
            number[j]=binary_decimal(binary[j]);
        }

        int flag=0;

        for(j=0;j<4;j++)
        {
            if(decimal[j]!=number[j])
            {
                flag=1;
            }
        }

        if(flag==1)
        {
            printf("Case %d: No\n",i);
        }
        else
        {
            printf("Case %d: Yes\n",i);
        }
    }

    return 0;
}
