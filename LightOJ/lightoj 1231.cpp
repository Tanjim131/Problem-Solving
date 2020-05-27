#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair < int , int >
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

const int MOD = 100000007;

LL ara[55];
int val[55];
int dp[55][1005];
int n; LL k;

LL call(int i,LL sum){
    if(i == n){
        if(sum == 0) return 1;
        return 0;
    }
    if(dp[i][sum] != -1) return dp[i][sum];
    LL ans = 0;
    for(int j = 0 ; j <= val[i] ; j++){
        if(sum - j * ara[i] >= 0){
            ans += call(i + 1,sum - j * ara[i]);
            ans %= MOD;
        }
    }
    return dp[i][sum] = ans % MOD;
}

int main(){
    //infile; outfile;
    int T,r = 0;
    scanf("%d",&T);
    while(T--){
        memset(dp,-1,sizeof(dp));
        scanf("%d %lld",&n,&k);
        for(int i = 0 ; i < n ; i++) scanf("%d",&ara[i]);
        for(int i = 0 ; i < n ; i++) scanf("%d",&val[i]);
        LL counter = call(0,k);
        printf("Case %d: %lld\n",++r,counter);
    }

    return 0;
}


