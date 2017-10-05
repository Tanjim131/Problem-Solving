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

int ara[205][205];
int dp[205][205];
int n;

int ret(int row,int col){
    if(row == (2 * n - 1) || col < 0) return 0;
    if(dp[row][col] != -1) return dp[row][col];
    int ans = 0;
    if(row < n - 1) ans = max(ret(row + 1,col),ret(row + 1,col + 1)) + ara[row][col];
    else ans = max(ret(row + 1,col),ret(row + 1,col - 1)) + ara[row][col];
    return dp[row][col] = ans;
}

int main(){
    //infile;outfile;
    int T,k = 0;
    scanf("%d",&T);
    while(T--){
        memset(dp,-1,sizeof(dp));
        memset(ara,0,sizeof(ara));
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i + 1; j++){
                scanf("%d",&ara[i][j]);
            }
        }
        for(int i = n ; i < 2 * n - 1 ; i++){
            for(int j = 0 ; j < (2 * n - 1) - i ; j++){
                scanf("%d",&ara[i][j]);
            }
        }
        int counter = ret(0,0);
        printf("Case %d: %d\n",++k,counter);
    }

    return 0;
}
