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

int ara[10005];
int n,k;
int dp[105][10005];

inline int MOD(int a){
    int r = a % k;
    return r < 0 ? r + k : r;
}

bool ret(int val,int pos){
    if(pos == n ){
        val = MOD(val);
        if(val == 0) return true;
        return false;
    }
    //cout << "val " << val << " pos " << pos << endl;
    if(dp[val][pos] != -1) return dp[val][pos];

    int ans1 = ret ( MOD (val + MOD(ara[pos]) ) , pos + 1 );
    int ans2 = ret ( MOD (val - ara[pos]) , pos + 1 );

    return dp[val][pos] = ans1 | ans2;
}

int main(){
    //infile;outfile;
    int T;
    scanf("%d",&T);
    while(T--){
        memset(dp,-1,sizeof(dp));
        scanf("%d %d",&n,&k);
        for(int i = 0 ; i < n ; i++) scanf("%d",&ara[i]);
        int qq = ret(0,0);
        if(qq) printf("Divisible\n");
        else printf("Not divisible\n");
    }
    return 0;
}


