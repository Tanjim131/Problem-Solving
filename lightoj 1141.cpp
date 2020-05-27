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

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

const int MAXN = 1000 + 5;
vector < int > vv[MAXN];
bool visit[MAXN];
int dist[MAXN];

/******* Sieve Routine *********/

int status[MAXN];
int prime[200 + 5];

void sieve(int N){
    memset(status,0,sizeof(status));
    // initially we are assuming all the numbers are prime

    // special case for 1
    status[1] = 1;
    // discarding multiples of 2
    for(int i = 4 ; i <= N ; i += 2) status[i] = 1;


    int sqrtN = (int) (sqrt ((double) N));
    // computing sqrt(N) only once because it is costly computing it inside a loop

    // only accounting the odd numbers and their multiples
    for(int i = 3 ; i <= sqrtN ; i += 2){
        if(status[i] == 0){
            // if this is still a prime then discard its multiples
            // first multiple that needs to be discarded starts at i * i
            // all the previous ones have already been discarded
            for(int j = i * i ; j <= N ; j += (i + i)) {
                //printf("Marking %d as not prime\n",j);
                status[j] = 1;
            }
        }
    }

    int counter = 0;
    prime[counter++] = 2;
    for(int i = 3 ; i < MAXN ; i += 2){
        if(status[i] == 0){
            prime[counter++] = i;
        }
    }
}

/******* Sieve Routine End ***********/

/****** Prime Factorize Routine ******/

void primeFactorize(int n){
    int sqrtN = (int) (sqrt ((double) n));

    int original = n;
    for(int i = 0 ; prime[i] <= sqrtN ; i++){
        if(n % prime[i] == 0){
            vv[original].pb(prime[i]);
            while(n % prime[i] == 0){
                n /= prime[i];
            }
        }
    }

    if(n > 1) vv[original].pb(n);
}

/****** Prime Factorize Routine End ******/

void precalculate(){
    for(int i = 1 ; i <= 1000 ; i++){
        primeFactorize(i);
    }
}



int bfs(int source,int destination){
    memset(visit,0,sizeof(visit));
    memset(dist,0,sizeof(dist));

    queue < int > q;
    q.push(source);

    while(!q.empty()){
        source = q.front();
        q.pop();

        for(int i = 0 ; i < vv[source].size() ; i++){
            int adj = vv[source][i];
            int sum = source + adj;
            //printf("Going from %d to %d with adj %d\n",source,sum,adj);

            if(!visit[sum] && sum <= destination){
                visit[sum] = true;
                dist[sum] = dist[source] + 1;
                //cout << "sum " << sum << " dest " << destination << endl;
                q.push(sum);
            }
        }
    }

    return dist[destination];
}

int main(){
    sieve(MAXN);
    precalculate();

    int T,kase = 0;
    scanf("%d",&T);
    while(T--){
        int a,b;
        scanf("%d %d",&a,&b);
        if(a == b) printf("Case %d: 0\n",++kase);
        else if(!status[a]) printf("Case %d: -1\n",++kase);
        else{
            int ans = bfs(a,b);
            if(ans == 0) printf("Case %d: -1\n",++kase);
            else printf("Case %d: %d\n",++kase,ans);
        }
    }
    return 0;
}

