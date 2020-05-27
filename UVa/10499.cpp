#include <iostream>
#include <cstdio>

using namespace std;

#define LL long long


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    LL n;
    while(scanf("%lld",&n) != EOF){
        if(n < 0) break;
        if(n == 1) printf("0%%\n");
        else printf("%lld%%\n",n * 25);
    }
    return 0;
}
