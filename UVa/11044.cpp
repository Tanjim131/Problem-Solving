#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

#define LL long long

int main(){
    int T,k = 0;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d %d",&n,&m);
        if(n < 3 || m < 3) printf("0\n");
        else{
            LL p = ceil((n - 2) * 1.0 /3);
            LL q = ceil((m - 2) * 1.0 /3);

            printf("%lld\n",p * q);
        }
    }

    return 0;
}
