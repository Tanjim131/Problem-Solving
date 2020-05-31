#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<utility>
 
using namespace std;
 
const int MAXN = 205;
const int MAX_VALUE = 15000;
 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define LL long long
 
vector< vector <pii > > edges(MAXN);
int simul[MAXN][MAXN];
int vis_mst[MAXN]; // visit array for minimum spanning tree
int vis_dfs[MAXN];
int par[MAXN];
int value[MAXN];
 
inline void init(){
    for(int i = 0 ; i < MAXN ; i++){
        value[i] = MAX_VALUE;
    }
}
 
pii build(vector< vector< pii > > &MST,int source){
    memset(vis_mst,0,sizeof(vis_mst));
    memset(par,-1,sizeof(par));
    init();
 
    priority_queue < pii, vector <pii>, greater <pii> > pq;
 
    int edge = 0,mincost = 0;
    pq.push(mp(0,source)); /* because in priority_queue the sorting is based on first element */
                            /* here we are sorting the edges based on their weights */
 
    pii top; int y;
 
    while(!pq.empty()){
        top = pq.top();
        pq.pop();
 
        if(vis_mst[top.second] == true) continue; // cycle checking
 
         if(par[top.second] != -1){
            MST[par[top.second]].pb(top);
            MST[top.second].pb(mp(top.first,par[top.second]));
            edge++;
        }
 
        mincost += top.first;
 
        vis_mst[top.second] = true;
 
        for(int i = 0 ; i < edges[top.second].size() ; i++){
            y = edges[top.second][i].second;
            if(vis_mst[y] == false) {
                int d = edges[top.second][i].first;
                if(d < value[y]){
                    par[y] = top.second;
                    value[y] = d;
                    pq.push(edges[top.second][i]);
                }
            }
        }
    }
    return mp(edge,mincost);
}
 
void dfs(int source){
    vis_dfs[source] = 1;
    for(int i = 0 ; i < edges[source].size() ; i++){
        if(vis_dfs[edges[source][i].second] == 0){
            dfs(edges[source][i].second);
        }
    }
}
 
int connected(int nodes){
    int tot = 0;
    memset(vis_dfs,0,sizeof(vis_dfs));
    for(int i = 1 ; i <= nodes ; i++){
        if(vis_dfs[i] == 0){
            dfs(i);
            tot++;
        }
        if(tot > 1) return 0;
    }
    return 1;
}
 
int main(){
    int T,k = 0;
    scanf("%d",&T);
 
    while(T--){
        int N,W; // N - number of fields , W - number of weeks
        scanf("%d %d",&N,&W);
 
        for(int i = 0 ; i < MAXN ; i++) edges[i].clear();
        for(int i = 0 ; i < MAXN ; i++){
            for(int j = 0 ; j < MAXN ; j++){
                simul[i][j] = MAX_VALUE;
            }
        }
 
        printf("Case %d:\n",++k);
 
        bool flag = false; int prev = 0;
 
        for(int i = 0 ; i < W ; i++){
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
 
            vector< vector<pii> > MST(MAXN);
 
            if(simul[x][y] > w || simul[y][x] > w){
                simul[x][y] = w;
                simul[y][x] = w;
 
                edges[x].pb(mp(w,y));
                edges[y].pb(mp(w,x));
            }
            else{
                printf("%d\n",prev);
                continue;
            }
 
            if(flag){
                pii counter = build(MST,1);
                prev = counter.second;
                printf("%d\n",counter.second);
                edges = MST;
            }
            else{
                if(connected(N) == 1){
                    flag = true;
                    pii counter = build(MST,1);
                    prev = counter.second;
                    printf("%d\n",counter.second);
                    edges = MST;
                }
                else { printf("-1\n"); prev = -1; }
            }
        }
    }
    return 0;
}
 