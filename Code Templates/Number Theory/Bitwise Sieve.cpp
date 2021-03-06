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
    printf("%d\n",counter);
}

int main(){
    bitwiseSieve();
    return 0;
}


