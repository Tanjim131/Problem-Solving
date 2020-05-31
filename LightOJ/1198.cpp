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
#define pii pair < int , int >
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)
 
//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
 
const int MAXN = 50 + 5;
int p_one[MAXN],p_two[MAXN];
int dp[MAXN][MAXN];
int N;
 
int bs(int num){
    int low = 0 , high = N - 1;
    int idx = -1;
 
    while(low <= high){
        int mid = (low + high) >> 1;
 
        if(p_one[mid] > num){
            idx = mid;
            high = mid - 1;
        }
 
        else low = mid + 1;
    }
 
    return idx;
}
 
int call(int i,int j){
    if(i >= N || j >= N) return 0;
 
    if(dp[i][j] != -1) return dp[i][j];
 
    int ret = 0;
 
    if(p_one[i] > p_two[j]) ret = 2 + call(i + 1,j + 1);
    else if(p_one[i] == p_two[j]){
        ret = 1 + call(i + 1,j + 1);
 
        int qq = bs(p_two[j]);
 
        if(qq != -1){
            ret = max(ret,2 + call(qq + 1,j + 1));
        }
    }
    else ret = call(i + 1,j);
 
    return dp[i][j] = ret;
}
 
int main(){
    int T,kase = 0; scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
 
        memset(dp,-1,sizeof(dp));
 
        for(int i = 0 ; i < N ; i++) scanf("%d",&p_one[i]);
        for(int i = 0 ; i < N ; i++) scanf("%d",&p_two[i]);
 
        sort(p_one,p_one + N);
        sort(p_two,p_two + N);
 
        printf("Case %d: %d\n",++kase,call(0,0));
 
    }
    return 0;
}