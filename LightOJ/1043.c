#include<stdio.h>
#include<math.h>
 
int main()
 
{
    int T,i;
    scanf("%d",&T);
 
    for(i=1;i<=T;i++)
 
    {
        double ab,ac,bc,ratio,s,area;
        scanf("%lf %lf %lf %lf",&ab,&ac,&bc,&ratio);
 
        ratio= (1+ratio)/ratio;
 
        s=(ab+ac+bc)/2;
 
        area=sqrt(s*(s-ab)*(s-ac)*(s-bc));
 
        double ade= area/ratio;
 
        double ad=sqrt((ade/area)*(ab*ab));
 
        printf("Case %d: %0.9lf\n",i,ad);
    }
 
    return 0;
}
 