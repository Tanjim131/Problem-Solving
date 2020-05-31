#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
 
using namespace std;
 
const int MAXN = 10005;
const int MOD = 10000007;
 
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d", &T);
    long long int a,b,c,d,e,f,n;
    for(int ti=0; ti<T; ti++){
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: ", ti+1);
        switch(n){
            case 0: printf("%lld\n", a % MOD);
                    break;
            case 1: printf("%lld\n", b % MOD);
                    break;
            case 2: printf("%lld\n", c % MOD);
                    break;
            case 3: printf("%lld\n", d % MOD);
                    break;
            case 4: printf("%lld\n", e % MOD);
                    break;
            case 5: printf("%lld\n", f % MOD);
                    break;
 
            default:
                long long *arr = new long long [n + 5];
                arr[0] = a;
                arr[1] = b;
                arr[2] = c;
                arr[3] = d;
                arr[4] = e;
                arr[5] = f;
                for(int i=6; i<=n; i++){
                    arr[i]= (arr[i-1] % MOD+arr[i-2] % MOD+arr[i-3] % MOD+arr[i-4] % MOD+arr[i-5] % MOD+arr[i-6] % MOD) % MOD;
                }
                printf("%lld\n", arr[n]);
        }
    }
    return 0;
}
 