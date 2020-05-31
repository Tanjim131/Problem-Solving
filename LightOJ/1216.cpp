#include<cstdio>
#include<cmath>
#include<iostream>
 
#define pi (2.0)*acos(0.0)
 
using namespace std;
 
int main(){
    int T,k = 0;
    scanf("%d",&T);
 
    while(T--){
        int r1,r2,h,p;
        scanf("%d %d %d %d",&r1,&r2,&h,&p);
 
        double rat = r2/(r1 * 1.0);
        double H = (rat * h)/(1 - rat);
 
        rat = H/(H + p);
 
        double r3 = r2/rat;
 
        double v1 = (1/(3 * 1.0)) * pi * r3 * r3 * (H + p);
        double v2 = (1/(3 * 1.0)) * pi * r2 * r2 * (H);
 
        printf("Case %d: %0.10f\n",++k,v1 - v2);
    }
 
    return 0;
}