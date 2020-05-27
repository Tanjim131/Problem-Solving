#include <iostream>
#include <cstdio>

using namespace std;

#define LL long long

LL bm(LL base,LL power,LL mod){
    if(power == 0) return 1;
    LL ret = bm(base,(power >> 1),mod);
    ret = (ret * ret) % mod;
    if(power & 1) ret = (ret * base) % mod;
    //printf("base %lld power %lld mod %lld ret %lld\n",base,power,mod,ret);
    return ret;
}

int main(){
    LL a,b,m;
    while(scanf("%lld %lld %lld",&a,&b,&m) != EOF){
        printf("%lld\n",bm(a,b,m));
    }
    return 0;
}

