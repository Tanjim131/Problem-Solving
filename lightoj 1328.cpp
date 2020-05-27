#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair < int , int >

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

const int MAXN = 100000 + 5;
const int MOD = 1000007;
LL ara[MAXN];
LL cumulative[MAXN];

void fillup(int n,int k,int c,int a_0){
    ara[0] = a_0;
    for(int i = 1 ; i < n ; i++){
        ara[i] = (k * ara[i - 1] + c) % MOD;
    }
}

LL gen(int n){
    cumulative[0] = ara[0];

    for(int i = 1 ; i < n ; i++){
        cumulative[i] = cumulative[i - 1] + ara[i];
    }

    LL sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += (n - i - 1) * ara[i] - (cumulative[n - 1] - cumulative[i]) ;
    }

    return sum;
}

int main(){
    int T,kase = 0;
    scanf("%d",&T);
    while(T--){
        int k,c,n,a_0;
        scanf("%d %d %d %d",&k,&c,&n,&a_0);
        fillup(n,k,c,a_0);
        sort( ara, ara + n, greater<int>() );
        printf("Case %d: %lld\n",++kase,gen(n));
    }
    return 0;
}

