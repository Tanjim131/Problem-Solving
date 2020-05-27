#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double area(int x1,int y1,int r1,int x2,int y2,int y2)
{
    double rr1=r1*r1,rr2=r2*r2;

    double distance= sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));

    if(d>=r1+r2 || d==0) return 0;

    else if(d<=abs(r1-r2) || d==0 && r1>r2) return pi*rr1;

    else if(d<=abs(r1-r2) || d==0 && r1<r2) return pi*rr2;

    else if

}
