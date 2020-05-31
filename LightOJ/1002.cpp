#include <cstdio>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
#define MAXN 505
#define MAX_VALUE 30000
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define LL long long
 
vector<pii>edges[MAXN];
vector<int>MST[MAXN];
int vis[MAXN];
int par[MAXN];
int value[MAXN];
 
inline void init(){
    for(int i = 0 ; i < MAXN ; i++){
        value[i] = MAX_VALUE;
    }
}
 
void MinimumSpanningTree(int source){
    memset(vis,0,sizeof(vis));
    memset(par,-1,sizeof(par));
    init();
    priority_queue < pii,vector<pii>,greater<pii> > pq;
    pq.push(mp(0,source));
    value[source] = 0;
 
    pii top;
    int y;
 
    while(!pq.empty()){
        top = pq.top();
        pq.pop();
 
        if(vis[top.second] == 1) continue; // cycle checking
 
        if(par[top.second] != -1){
            MST[par[top.second]].pb(top.second);
            MST[top.second].pb(par[top.second]);
        }
 
        vis[top.second] = 1;
 
        for(int i = 0 ; i < edges[top.second].size() ; i++){
            y = edges[top.second][i].second;
            if(vis[y] == 0) {
                int d = edges[top.second][i].first;
                if(d < value[y]){
                    par[y] = top.second;
                    value[y] = d;
                    pq.push(edges[top.second][i]);
                }
            }
        }
    }
}
 
void bfs(int source){
    memset(vis,0,sizeof(vis));
    queue<int>q;
    vis[source] = 1;
    value[source] = 0;
    q.push(source);
    int f;
 
    while(!q.empty()){
        f = q.front();
        q.pop();
 
        for(int i = 0 ; i < MST[f].size() ; i++){
            if(vis[MST[f][i]] == 0){
                vis[MST[f][i]] = 1;
                value[MST[f][i]] = max(value[MST[f][i]],value[par[MST[f][i]]]);
                q.push(MST[f][i]);
            }
        }
    }
}
 
int main(int argc, char const *argv[]){
    //freopen("lightoj1002in.txt","r",stdin);
    //freopen("lightoj1002out.txt","w",stdout);
    int T,k = 0;
    scanf("%d",&T);
 
    while(T--){
        int n,m;
        scanf("%d %d",&n,&m);
 
        for(int i = 0 ; i < MAXN ; i++) edges[i].clear();
        for(int i = 0 ; i < MAXN ; i++) MST[i].clear();
;
        for(int i = 0 ; i < m ; i++){
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
 
            edges[x].pb(mp(w,y));
            edges[y].pb(mp(w,x));
        }
 
        int source;
        scanf("%d",&source);
 
        MinimumSpanningTree(source);
 
        bfs(source);
 
        printf("Case %d:\n",++k);
 
        for(int i = 0 ; i < n ; i++){
            if(value[i] == MAX_VALUE) printf("Impossible\n");
            else printf("%d\n",value[i]);
        }
    }
    return 0;
}