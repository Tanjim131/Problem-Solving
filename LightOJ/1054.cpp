#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

#define LL long long
#define pb push_back
#define mp make_pair
#define PII pair < int , int >
#define infile(f) freopen(f,"r",stdin)
#define outfile(f) freopen(f,"w",stdout)

inline bool checkBit(int mask,int pos) { return (bool) (mask & (1 << pos)); }
inline int setBit(int mask,int pos) { return (mask | (1 << pos)); }

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

const int MAXN = 50000;
const int MOD = 1000000007;
int status[(MAXN >> (5)) + 2]; // MAXN/32 + 2
int prime[5150]; // prime number distribution pi(x) = x/ln(x)

/*
for generating statuss up to 1e6
we're using bitwise sieve
so memory needed (1e6/32) bytes
because every 32 bits or 4 bytes (sizeof(int)) is enough for 32 integers
*/

void bitwiseSieve(){
    int sqrtN = (int) (sqrt((double) MAXN));
    for(int i = 3 ; i <= sqrtN ; i += 2){
        if(!checkBit(status[i >> 5],i & 31)){ // i/32 th index and i & 31 th bit for i
            for(int j = i * i ; j <= MAXN ; j += (i << 1)){ // i << 1 , only the odd multiples
                status[j >> 5] = setBit(status[j >> 5],j & 31); // j % 32 is same as j & 31
            }
        }
    }
    int counter = 0;
    prime[counter++] = 2;
    for(int i = 3 ; i <= MAXN ; i += 2){
        if(!checkBit(status[i >> 5],i & 31)){
            prime[counter++] = i;
        }
    }
    //printf("%d\n",counter);
}

LL bigmod(LL base,LL exponent){
    if(!exponent) return 1;
    LL ret = bigmod(base,exponent >> 1);
    ret = (ret * 1LL * ret) % MOD;
    if(exponent & 1) ret = (ret * base) % MOD;
    return ret;
}

LL modularInverse(LL base){
    return bigmod(base,MOD - 2) % MOD;
}

LL res(int num,int exp){

    // prime Factorization start
    vector < pair < int , LL > > v;

    int sqrtN = (int) (sqrt((double) num));

    for(int i = 0 ; prime[i] <= sqrtN ; i++){
        if(num % prime[i] == 0){
            int counter = 0;
            while(num % prime[i] == 0){
                counter++;
                num /= prime[i];
            }
            LL qq = counter * 1LL * exp ;
            v.pb(mp(prime[i],qq));
        }
    }

    if(num > 1){
        v.pb(mp(num,exp * 1LL));
    }

    // prime Factorization end

    LL ans = 1;

    for(int i = 0 ; i < v.size() ; i++){
        int pr = v[i].first;
        LL exp = v[i].second;
        LL bm = bigmod(pr,exp + 1) - 1;
        LL mdinv = modularInverse(pr - 1);
        ans = ((ans % MOD) * ((bm * mdinv) % MOD)) % MOD;
        if(ans < 0) ans += MOD;
    }

    return ans;
}

int main(){
    //infile("in.txt");
    //outfile("out.txt");
    bitwiseSieve();
    int T,kase = 0;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d %d",&n,&m);
        printf("Case %d: %lld\n",++kase,res(n,m));
    }
    return 0;
}


