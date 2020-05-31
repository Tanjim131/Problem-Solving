#include<cstdio>
#include<cmath>
 
using namespace std;
 
#define eps 1e-9
 
double check(double y,double c,double d){
    double h2 = sqrt(y * y - d * d);
    double len = (c * d) / h2;
    double len1 = d - len;
    double len2 = sqrt(c * c + len1 * len1);
    double rat = len1/d;
    double x = len2 / rat;
 
    return x;
}
 
double binary(double x,double y,double c){
    double low = 0.0;
    double high = (x < y) ? x : y;
    double mid;
 
    while(high - low > eps){
        mid = (low + high)/2;
 
        double temp = check(y,c,mid); // return value of x
 
        if(temp > x || temp < 0) high = mid;
 
        else low = mid;
 
    }
 
    return mid;
}
 
int main(){
    int T,k = 0;
    scanf("%d",&T);
 
    while(T--){
        double x,y,c;
        scanf("%lf %lf %lf",&x,&y,&c);
        double answer = binary(x,y,c);
        printf("Case %d: %0.10f\n",++k,answer);
    }
 
    return 0;
}