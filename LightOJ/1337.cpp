#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
#include<utility>
 
using namespace std;
 
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
 
const int MAXN = 505;
 
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
 
char edges[MAXN][MAXN];
int cost[MAXN][MAXN];
int vis1[MAXN][MAXN];
int vis2[MAXN][MAXN];
int row,col,counter;
 
int bfs(int sx,int sy){
    counter = 0;
    vis1[sx][sy] = 1;
    queue<pii>q;
    q.push(mp(sx,sy));
 
    while(!q.empty()){
        pii top = q.front();
        q.pop();
 
        for(int i = 0 ; i < 4 ; i++){
            int tx = top.first + dx[i];
            int ty = top.second + dy[i];
 
            if(tx >= 0 && tx < row && ty >= 0 && ty < col && edges[tx][ty] != '#' && vis1[tx][ty] == 0){
                if(edges[tx][ty] == 'C') counter++;
                vis1[tx][ty] = 1;
                q.push(mp(tx,ty));
            }
        }
    }
 
    cost[sx][sy] = counter;
 
    return counter;
}
 
void dfs(int sx,int sy){
    if(vis2[sx][sy] || sx < 0 || sx >= row || sy < 0 || sy >= col || edges[sx][sy] == '#') return;
    vis2[sx][sy] = 1;
    cost[sx][sy] = counter;
    for(int i = 0 ; i < 4 ; i++){
        dfs(sx + dx[i],sy + dy[i]);
    }
}
 
int main(){
    //freopen("crystalin.txt","r",stdin);
    //freopen("crystalout.txt","w",stdout);
    int T,k = 0;
    scanf("%d",&T);
 
    while(T--){
        int Q;
        scanf("%d %d %d",&row,&col,&Q);
 
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
        memset(cost,-1,sizeof(cost));
 
        for(int i = 0 ; i < row ; i++){
           scanf("%s",edges[i]);
        }
 
        printf("Case %d:\n",++k);
 
        for(int i = 0 ; i < Q ; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            --x,--y;
 
            if(!vis1[x][y]) {
                bfs(x,y);
                dfs(x,y);
            }
 
            printf("%d\n",cost[x][y]);
        }
    }
    return 0;
}
 