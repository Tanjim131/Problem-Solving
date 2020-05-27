#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define pii pair < int , int >
#define mp make_pair

const int MAXN = 15;
char ara[MAXN][MAXN];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int vis[MAXN][MAXN];
int n;

int bfs(int sx,int sy){
    memset(vis,0,sizeof(vis));
    queue < pii > q;
    vis[sx][sy] = 1;
    q.push(mp(sx,sy));
    int counter = 1;
    char check = 'A';
    bool f = true;
    while(!q.empty()){
        pii top = q.front();
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int xx = top.first + dx[i];
            int yy = top.second + dy[i];

            if(xx >= 0 && xx < n && yy >= 0 && yy < n && ara[xx][yy] != '#' && vis[xx][yy] == 0){
                if(ara[xx][yy] != '.'){
                    if((ara[xx][yy] - check) == 1){
                        counter += ara[xx][yy];
                        visit[xx][yy] = 1;
                        q.push(mp(xx,yy));
                    }
                }
                else{
                    vis[xx][yy] = 1;
                    q.push(mp(xx,yy));
                }
            }
        }
    }
    return f ? counter : -1;
}

int main(){
    int T,k = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int sx = 0 , sy = 0;
        for(int i = 0 ; i < n ; i++){
            scanf("%s",ara[i]);
            int len = strlen(ara[i]);
            for(int j = 0 ; j < len ; j++){
                if(ara[i][j] == 'A'){
                    sx = i;
                    sy = j;
                }
            }
        }
        int ans = bfs(sx,sy);
        if(ans == -1) printf("Case %d: Impossible\n",++k);
        else printf("Case %d: %d\n",++k,ans);
    }
    return 0;
}
