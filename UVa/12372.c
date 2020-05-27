#include<stdio.h>

int main()

{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)

    {
        int L,W,H;
        scanf("%d %d %d",&L,&W,&H);

        if( (L<=20 && W<=20 && H<=20) && (L*W*H<=8000)) printf("Case %d: good\n",i);
        else printf("Case %d: bad\n",i);
    }

    return 0;
}
