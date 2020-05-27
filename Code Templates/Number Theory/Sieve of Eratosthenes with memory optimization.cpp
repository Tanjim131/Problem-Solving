#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <sstream>

using namespace std;

#define LL long long
#define pb push_back
#define mp make_pair
#define PII pair < int , int >
#define infile(f) freopen(f,"r",stdin)
#define outfile(f) freopen(f,"w",stdout)

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

const int MAXN = 1000000 + 5; // adjust MAXN accordingly
// finding prime from 1 up to N
int status[(MAXN >> 1) + 1]; // we need space for only the odd numbers
int prime[80000]; // prime number distribution , pi(x) = x/ln(x) , adjust this according to MAXN

// If status[i] = 0 -> i is prime
// If status[i] = 1 -> i is not prime

void sieve(int N){

    for(int i = 1 ; i <= (N >> 1) ; i++) status[i] = 0; // for every i , 2 * i + 1 is the odd number, marking it as prime

    int sqrtN = (int) (sqrt ((double) N));
    // computing sqrt(N) only once because it is costly computing it inside a loop

    // only accounting the odd numbers and their multiples
    for(int i = 3 ; i <= sqrtN ; i += 2){
        if(status[i >> 1] == 0){
            // if this is still a prime then discard its multiples
            // first multiple that needs to be discarded starts at i * i
            // all the previous ones have already been discarded
            for(int j = i * i ; j <= N ; j += (i + i)) {
                //printf("Marking %d as not prime\n",j);
                status[j >> 1] = 1;
            }
        }
    }
    int counter = 0;
    prime[counter++] = 2;
    for(int i = 3 ; i <= N ; i += 2){
        if(status[i >> 1] == 0){
            prime[counter++] = i;
        }
    }
    printf("%d\n",counter);
}

int main(){
    int N;
    scanf("%d",&N);
    sieve(N);
    return 0;
}

