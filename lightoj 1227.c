#include<stdio.h>
#define ffor(i,A,B) for(i=(A);i<(B);i++)

int main()

{
    int T,i=0;
    scanf("%d",&T);

    while(T--)

    {
        int n,p,q;
        scanf("%d %d %d",&n,&p,&q);

        int ara[n];

        int j;

        ffor(j,0,n) scanf("%d",&ara[j]);

        int k,weight=0,counter=0;

        if(p>=n)
        {
             ffor(k,0,n)
            {
                weight+=ara[k];
                if(weight>q) break;
                counter++;
            }

            printf("Case %d: %d\n",++i,counter);

        }
        else
        {
            ffor(k,0,p)
            {
                weight+=ara[k];
                if(weight>q) break;
                counter++;
            }

            printf("Case %d: %d\n",++i,counter);
        }
    }

    return 0;
}
