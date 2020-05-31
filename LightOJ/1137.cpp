#include<cstdio>
#include<cmath>
 
using namespace std;
 
const double PI = 3.1415926535897932384626433832795;
const double eps = 0.0000000001;
 
inline double d2r(double degree){
    return (degree * PI) / 360.0;
}
 
double compute(double theta,double initial){
    double up = initial * theta * PI;
    double down = 360.0 * sin(d2r(theta));
    double ret = up/down;
    return ret;
}
 
double binary(double initial,double increase){
    double low = 0.0;
    double high = 180.0;
    double mid = 0.0;
 
    while(high - low > eps){
        mid = (low + high)/2;
 
        if(compute(mid,initial) > increase) high = mid;
        else low = mid;
    }
 
    return mid;
}
 
int main(){
   // freopen("loj 1137.txt","r",stdin);
    int T,k = 0;
    scanf("%d",&T);
 
    while(T--){
        double L,n,C; scanf("%lf %lf %lf",&L,&n,&C);
        double expand = (1 + n * C) * L;
 
        if(expand == L){
            printf("Case %d: 0\n",++k);
            continue;
        }
 
        double theta = binary(L,expand);
 
        double a = L/(2.0 * sin(d2r(theta)));
        double b = L/(2.0 * tan(d2r(theta)));
 
        double ans = a - b;
 
        printf("Case %d: %0.12f\n",++k,ans);
    }
 
    return 0;
}
 