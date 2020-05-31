#include<stdio.h>
 
int main()
 
{
    int T,i;
    scanf("%d",&T);
 
    for(i=1;i<=T;i++)
 
    {
        long long int n;
        scanf("%lld",&n);
 
        char number[1000];
 
        long long int j=0,k;
 
        while(n!=0)
        {
            k=n%2;
            number[j]=k+'0';
            n=n/2;
            j++;
        }
 
        number[j]='\0';
 
        int counter=0,x;
 
        for(x=0;number[x]!='\0';x++)
        {
            if(number[x]=='1')
            {
                counter++;
            }
        }
 
        if(counter%2==0)
        {
            printf("Case %d: even\n",i);
        }
        else
        {
            printf("Case %d: odd\n",i);
        }
    }
 
    return 0;
}