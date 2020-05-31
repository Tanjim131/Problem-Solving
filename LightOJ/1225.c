#include<stdio.h>
#include<string.h>
 
int main()
 
{
    int T,p;
    scanf("%d",&T);
 
    for(p=1;p<=T;p++)
 
    {
        char a[100];
        char b[100];
 
        scanf("%s",&a);
 
        int i,j;
 
        int length=strlen(a);
 
        for(i=length-1,j=0;i>=0,j<length;i--,j++)
        {
            b[j]=a[i];
        }
 
        int flag=0;
 
        for(i=0,j=0;i<length,j<length;i++,j++)
        {
            if(a[i]!=b[j])
            {
                flag=1;
            }
        }
 
        if(flag==1)
        {
            printf("Case %d: No\n",p);
        }
        else
        {
            printf("Case %d: Yes\n",p);
        }
 
 
    }
 
        return 0;
}