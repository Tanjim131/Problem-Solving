#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100005;
double ara[MAXN];

void precompute(){
    double ret = 0.0;
    for(int i = 1 ; i <= MAXN ; i++){
        ret += 1 / (i * 1.0);
        ara[i] = ret;
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    precompute();
    int T,k = 0;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        double ans = n * ara[n];
        printf("Case %d: %0.10f\n",++k,ans);
    }
    return 0;
}
