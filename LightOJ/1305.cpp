#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    int c=1;
    while(c<=t)
    {
        int ax,ay,bx,by,cx,cy;
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        double h,b;
        double h1,h2;
        double dx,dy,area;
        dx=ax+cx-bx;
        dy=ay+cy-by;
        h1=dx*(ay-by)+dy*(bx-ax)+ax*by-ay*bx;
        if(h1<0)
        {
            h1=h1*-1;
        }
        h2=sqrt(pow(ay-by,2)+pow(bx-ax,2));
        h=h1/h2;
        b=sqrt(pow(ax-bx,2)+pow(ay-by,2));
        area=h*b;
        cout<< setprecision(10) << "Case "<<c<<": "<<dx<<" "<<dy<<" "<<area<<endl;
        c++;
    }
    return 0;
}