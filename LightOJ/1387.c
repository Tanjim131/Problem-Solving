#include<stdio.h>
#include<string.h>

int main()

{
    int T,i=0;
    scanf("%d",&T);

    /*char a[]="report";
    char b[]="donate";*/

    while(T--)

    {
        int N;
        scanf("%d",&N);

        int j;

        int account=0;

        printf("Case %d:\n",++i);

        for(j=1;j<=N;j++)
        {
            char word[100];
            scanf("%s",&word);

             if(!strcmp(word,"report")) printf("%d\n",account);

            //else if(!strcmp(word,"donate"))
            else
            {
                int number;
                scanf("%d",&number);
                account+=number;
            }
        }
    }

    return 0;
}
