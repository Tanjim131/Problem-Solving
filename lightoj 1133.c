#include<stdio.h>

int main()

{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)
    {
       int n,m;
       scanf("%d %d",&n,&m);

       char a[10];

       int ara[n],ara1[n];

       int j;

       for(j=0;j<n;j++)
       {
           scanf("%d",&ara[j]);
       }

       int k,x,y,z,e,f,s,t,q,w;

       for(k=1;k<=m;k++)
       {
           scanf("%s",&a);

           if(a[0]=='S' && a[1]=='\0')
           {
               scanf("%d",&x);

               for(j=0;j<n;j++) ara[j]+=x;
           }
           else if(a[0]=='M' && a[1]=='\0')
           {
               scanf("%d",&y);

               for(j=0;j<n;j++) ara[j]*=y;
           }
           else if(a[0]=='D' && a[1]=='\0')
           {
               scanf("%d",&z);

               for(j=0;j<n;j++) ara[j]/=z;
           }
           else if(a[0]=='R' && a[1]=='\0')
           {
               for(e=0,f=(n-1);e<n,f>=0;e++,f--) ara1[e]=ara[f];

               for(e=0;e<n;e++) ara[e]=ara1[e];

           }
           else if(a[0]=='P' && a[1]=='\0')
           {
               scanf("%d %d",&s,&t);

               q=ara[s];
               ara[s]=ara[t];
               ara[t]=q;
           }
       }

       printf("Case %d:\n",i);

       for(j=0;j<n;j++)
       {
           printf("%d",ara[j]);

           if(j!=n-1) printf(" ");
       }

       printf("\n");

    }

    return 0;
}
