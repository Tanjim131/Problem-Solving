#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
 
using namespace std;
 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
 
const int MAXN = 30005;
const int MAX_VALUE = 10005;
 
vector<pii>edges[MAXN];
int vis[MAXN];
int cost[MAXN];
int node,c;
 
void dfs(int source){
    vis[source] = 1;
    for(int i = 0 ; i < edges[source].size() ; i++){
        if(vis[edges[source][i].second] == 0){
            cost[edges[source][i].second] = cost[source] + edges[source][i].first;
            if(c < cost[edges[source][i].second]){
                c = cost[edges[source][i].second];
                node = edges[source][i].second;
            }
            dfs(edges[source][i].second);
        }
    }
}
 
int main(){
    int T,k = 0;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
 
        for(int i = 0 ; i < MAXN ; i++) edges[i].clear();
        memset(vis,0,sizeof(vis));
        memset(cost,0,sizeof(cost));
        node = 0,c = 0;
 
        for(int i = 0 ; i < n - 1 ; i++){
            int u,v,w; scanf("%d %d %d",&u,&v,&w);
 
            edges[u].pb(mp(w,v));
            edges[v].pb(mp(w,u));
        }
 
        dfs(0);
 
        int cs = c;
 
        memset(vis,0,sizeof(vis));
        memset(cost,0,sizeof(cost));
 
        dfs(node);
 
        int _cs = c;
 
        int ans = (cs > _cs) ? cs : _cs;
 
        printf("Case %d: %d\n",++k,ans);
    }
    return 0;
}