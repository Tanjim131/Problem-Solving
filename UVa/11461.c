#include<stdio.h>
#include<math.h>

int main()

{
    long long int a,b;

    while(2==scanf("%lld %lld",&a,&b))
    {
        if(a==0 && b==0) break;

        else
        {
            long long int counter=0;

            long long int i;

            long long int y=sqrt(a);

            if(a==y*y)
            {

                for(i=y;;i++)
                {
                    long long int x=i*i;
                    if(x>b) break;
                    counter++;
                }

                printf("%lld\n",counter);
            }
            else
            {
                for(i=y+1;;i++)
                {
                    long long int x=i*i;
                    if(x>b) break;
                    counter++;
                }

                printf("%lld\n",counter);
            }

        }
    }

    return 0;
}


