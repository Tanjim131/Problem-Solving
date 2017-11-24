#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>

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

const int MAXN = 100 + 5;
int status[MAXN];
//int prime[30]; // prime number distribution - pi(x) = x/ln(x)
//vector < PII > factor[MAXN];
//int ans[MAXN][MAXN];

/*

Idea:Run sieve, compute primes up to 100, prime factorize every number up to 100 in this format : primefactorize(n) = p1^(e1) . p2(e2) . .....
then run process to add the exponents

this can be simplified by Legendre's Formula, the highest power of a prime that divides n!
*/


inline void sieve(){
    for(int i = 4 ; i < MAXN ; i += 2)  status[i] = 1;
    int sqrtN = (int) (sqrt((double) MAXN));
    for(int i = 3 ; i <= sqrtN ; i += 2){
        if(status[i] == 0){
            // this number is still prime
            for(int j = i * i ; j < MAXN ; j += (i << 1)){
                status[j] = 1;
            }
        }
    }
    /*int counter = 0;
    prime[counter++] = 2;
    for(int i = 3 ; i < MAXN ; i += 2){
        if(!status[i]) {
            //printf("%d\n",i);
            prime[counter++] = i;
        }
    }*/
}

/*inline void primeFactorize(int num){
    int temp = num;
    int sqrtN = (int) (sqrt((double) num));
    for(int i = 0 ; prime[i] <= sqrtN ; i++){
        if(num % prime[i] == 0){
            int counter = 0;
            while(num % prime[i] == 0){
                counter++;
                num /= prime[i];
            }
            factor[temp].pb(mp(prime[i],counter));
        }
    }
    if(num > 1){
        factor[temp].pb(mp(num,1));
    }
}*/

/*void allFactor(){
    for(int i = 2 ; i <= 100 ; i++){
        primeFactorize(i);
    }
}*/

inline int ret(int num,int prime){
    // returns the highest exponent of a prime number that divides n!
    // Legendre's Formula
    // wiki Link : https://en.wikipedia.org/wiki/Legendre%27s_formula
    int counter = 0;
    while(num){
        counter += num/prime;
        num /= prime;
    }
    return counter;
}

inline void process(int N){
    for(int i = 2 ; i <= N ; i++){
        if(!status[i]) {
            //ans[N][i]++;
            if(i != 2) printf(" *");
            printf(" %d (%d)",i,ret(N,i));
        }

        /*else{
            for(int j = 0 ; j < factor[i].size() ; j++){
                int pr = factor[i][j].first;
                int counter = factor[i][j].second;
                ans[N][pr] += counter;
            }
        }*/
    }
}

int main(){
    //infile("in.txt");
    //outfile("out.txt");
    sieve();
    //allFactor();
    int T,kase = 0;
    scanf("%d",&T);
    while(T--){
        //memset(ans,0,sizeof(ans));
        int N;
        scanf("%d",&N);
        printf("Case %d: %d =",++kase,N);
        process(N);
        /*for(int i = 0 ; prime[i] <= N ; i++){
            if(ans[N][prime[i]]){
                if(i) printf(" *");
                printf(" %d (%d)",prime[i],ans[N][prime[i]]);
            }
        }*/
        printf("\n");
    }
    return 0;
}


