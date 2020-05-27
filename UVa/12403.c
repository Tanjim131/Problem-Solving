#include<stdio.h>

int main()

{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        char a[100];

        scanf("%s",&a);

        int sum=0;

        int k;


        if(a[0]=='d' && a[1]=='o' && a[2]=='n' && a[3]=='a' && a[4]=='t' && a[5]=='e' && a[6]=='\0' && a[7]==' ' && a[8]=='k')
        {
            scanf("%d",&k);
            sum+=k;
        }

        else if(a[0]=='r' && a[1]=='e' && a[2]=='p' && a[3]=='o' && a[4]=='r' && a[5]=='t' && a[6]=='\0')
        {
            printf("%d\n",sum);
        }


    }

    return 0;
}
