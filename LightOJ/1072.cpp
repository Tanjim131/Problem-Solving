#include<cstdio>
#include<cmath>
 
#define pi (2.0)*acos(0.0)
 
using namespace std;
 
int main(){
    int T,k = 0;
    scanf("%d",&T);
 
    while(T--){
        double R,n; scanf("%lf %lf",&R,&n);
 
        double ang = pi/n;
        double temp = sin(ang);
 
        double ret = (R * temp)/(temp + 1);
 
        printf("Case %d: %0.10f\n",++k,ret);
    }
 
    return 0;
}