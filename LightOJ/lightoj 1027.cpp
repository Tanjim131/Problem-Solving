#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 105;
int ara[MAXN];

int gcd(int p,int q){
    if(q == 0) return p;
    return gcd(q,p % q);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,k = 0;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int counter = 0;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&ara[i]);
            sum += abs(ara[i]);
            if(ara[i] >= 0) counter++;
        }
        if(counter == 0) printf("Case %d: inf\n",++k);
        else{
            int ret = gcd(sum,counter);
            sum /= ret ; counter /= ret;
            printf("Case %d: %d/%d\n",++k,sum,counter);
        }
    }
    return 0;
}
