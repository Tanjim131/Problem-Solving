#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

const double pi = 3.1415926535897932384626;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int l,w,h,theta;
    while(scanf("%d %d %d %d",&l,&w,&h,&theta) != EOF){
        double angle = (theta * pi) / 180.0;
        double temp = tan(angle) * l;
        double side = h - temp;
        double area = 0.5 * (side + h) * l;
        double ret = area * w;
        printf("%0.3f mL\n",ret);
    }
    return 0;
}
