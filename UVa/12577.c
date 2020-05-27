#include<stdio.h>

int main()

{
    char word[10],i=1;

    while(1==scanf("%s",word))
    {
        if(word[0]=='*' && word[1]=='\0')
        {
            break;
        }
        else
        {
            if(word[0]=='H' && word[1]=='a' && word[2]=='j' && word[3]=='j' && word[4]=='\0')
            {
                printf("Case %d: Hajj-e-Akbar\n",i);
            }
            else if(word[0]=='U' && word[1]=='m' && word[2]=='r' && word[3]=='a' && word[4]=='h' && word[5]=='\0')
            {
                printf("Case %d: Hajj-e-Asghar\n",i);
            }
        }
        i++;
    }

    return 0;
}
