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

const int MAXN = 1000000 + 5;
int status[(MAXN >> (5)) + 2];
int prime[80000]; // prime number distribution pi(x) = x/ln(x) so in 1e6 range there are about ~80000 primes

/*
for generating statuss up to 1e6
we're using bitwise sieve
so memory needed (1e6/32) bytes
because every 32 bits or 4 bytes (sizeof(int)) is enough for 32 integers
*/

void bitwiseSieve(){
    int sqrtN = (int) (sqrt((double) MAXN));
    for(int i = 3 ; i <= sqrtN ; i += 2){
        if(!checkBit(status[i >> 5],i & 31)){
            for(int j = i * i ; j <= MAXN ; j += (i << 1)){
                status[j >> 5] = setBit(status[j >> 5],j & 31);
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
}

int primeFactorize(LL num){
    int sqrtN = (int) (sqrt((double) num));
    int ans = 1;
    for(int i = 0 ; prime[i] <= sqrtN ; i++){
        if(num % prime[i] == 0){
            int counter = 0;
            while(num % prime[i] == 0){
                counter++;
                num /= prime[i];
            }
            sqrtN = (int) (sqrt((double) num)); // this is a crucial optimization
            ans = ans * (counter + 1);
            if(num <= 1) break;
        }
    }
    if(num > 1) { ans = (ans << 1); }
    return ans;
}

int main(){
    //infile("in.txt");
    //outfile("out.txt");
    bitwiseSieve();
    int T,kase = 0;
    scanf("%d",&T);
    while(T--){
        LL n; scanf("%lld",&n);
        printf("Case %d: %d\n",++kase,primeFactorize(n) - 1);
    }
    return 0;
}


