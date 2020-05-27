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
#define pii pair < int , int >
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

int ara[105];
int dp[10005];
int n;

void precalculate(){
    for(int i = 1 ; i <= 100 ; i++) ara[i] = i * i;
}

int call(int sum){
    if(sum == 0) return 0;
    if(dp[sum] != -1) return dp[sum];
    int ans = 1e5;
    for(int i = 1 ; i <= 100 ; i++){
        if(sum - ara[i] >= 0) ans = min(ans , 1 + call(sum - ara[i]));
    }
    return dp[sum] = ans;
}

int main(){
    //infile;outfile;
    precalculate();
    int T;
    scanf("%d",&T);
    memset(dp,-1,sizeof(dp));
    while(T--){
        scanf("%d",&n);
        int counter = call(n);
        printf("%d\n",counter);
    }
    return 0;
}


