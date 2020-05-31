#include<cstdio>
#include<cmath>
 
using namespace std;
 
double compute(double rat){
    double a = sqrt(rat * rat + 1);
    double b = asin(1.0/a);
 
    double tot = rat + a * b;
    double ans = 200.0/tot;
 
    return ans;
}
 
int main(){
    int T,k = 0;
    scanf("%d",&T);
 
    while(T--){
        int a,b; char c;
        scanf("%d %c %d",&a,&c,&b);
 
        double rat = (a * 1.0)/b;
 
        double w = compute(rat);
        double l = rat * w;
 
        printf("Case %d: %0.10f %0.10f\n",++k,l,w);
    }
 
    return 0;
}