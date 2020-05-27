#include<stdio.h>
#include<string.h>

int main()

{
    char number[1000];

    while(1==scanf("%s",number))

    {

        if(number[0]=='0' && number[1]=='\0')
        {
            break;
        }

        else
        {

            int length=strlen(number);

            int i,sum_even=0,sum_odd=0;

            for(i=0;i<length;i++)

            {
                if(i%2==0)
                {
                    sum_even+= number[i]-'0';
                }
                else
                {
                    sum_odd+=number[i]-'0';
                }
            }

            if((sum_even-sum_odd)%11==0)

            {
                printf("%s is a multiple of 11.\n",number);
            }
            else
            {
                printf("%s is not a multiple of 11.\n",number);
            }

        }
    }

    return 0;

}
