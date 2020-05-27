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

vector < int > ara[25];
int dp[205][25];
int budget,n;

int process(int money,int g){
    if(money > budget) return -1;
    if(g == n) return money;
    if(dp[money][g] != -1) return dp[money][g];
    int ans = -1;
    for(int i = 0 ; i < ara[g].size() ; i++){
        //printf("Calling function with money = %d and g = %d\n",money + ara[g][i],g + 1);
        ans = max(ans,process(money + ara[g][i] ,g + 1));
    }
    //printf("dp[%d][%d] = %d\n",money,g,ans);
    return dp[money][g] = ans;
}

int main(){
    //infile;outfile;
    int T; scanf("%d",&T);
    while(T--){
        memset(dp,-1,sizeof(dp));
        scanf("%d %d",&budget,&n);
        for(int i = 0 ; i < 25 ; i++) ara[i].clear();
        for(int i = 0 ; i < n ; i++){
            int x; scanf("%d",&x);
            for(int j = 0 ; j < x ; j++){
                int qq; scanf("%d",&qq);
                ara[i].pb(qq);
            }
        }
        int counter = process(0,0);
        if(counter == -1) printf("no solution\n");
        else printf("%d\n",counter);
    }
    return 0;
}


