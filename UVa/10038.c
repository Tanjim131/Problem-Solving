#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

int main()

{
    int n;
    while(1==scanf("%d",&n))
    {

        int ara[n],ara1[n-1];

        int i;

        for(i=0;i<n;i++)
        {
            scanf("%d",&ara[i]);
        }

        int j;


        for(i=0,j=i+1;i<n,j<n;i++,j++)
        {
            ara1[i]= abs(ara[i]-ara[j]);
        }

        int t;




        int flag=0;


        for(i=0,j=1;i<(n-1),j<=(n-1);i++,j++)
        {
            if(ara1[i]==j) flag=0;

            else
            {
                flag=1;
                break;
            }
        }

        if(flag==0) printf("Jolly\n");

        else printf("Not jolly\n");


    }

    return 0;
}

