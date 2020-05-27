#include<stdio.h>
#include<string.h>

int main()

{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        char word[1000];

        scanf("%s",&word);

        int length=strlen(word);

        if(length==5)
        {
            printf("3\n");
        }
        else if(length==3)
        {
            if( (word[0]=='o' && word[1]=='n') || (word[0]=='o' && word[2]=='e') || (word[1]=='n' && word[2]=='e') )
            {
                printf("1\n");
            }
            else
            {
                printf("2\n");
            }
        }
    }

    return 0;
}