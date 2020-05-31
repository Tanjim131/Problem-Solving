#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
#include<map>
 
using namespace std;
 
#define MAXN 20005
#define pb push_back
 
vector <int> edges[MAXN];
int vis[MAXN];
int color[MAXN];
int mx,zero,one;
 
void bfs(int source){
    queue <int> q;
    q.push(source);
    vis[source] = 1;
    zero = 0, one = 0;
    color[source] = 0;
    zero++;
    int p;
 
    while(!q.empty()){
        p = q.front();
        q.pop();
 
        for(int i = 0 ; i < edges[p].size() ; i++){
            if(vis[edges[p][i]] == 0){
                vis[edges[p][i]] = 1;
                color[edges[p][i]] = color[p] ^ 1;
                if(color[edges[p][i]] == 1) one++;
                else zero++;
                q.push(edges[p][i]);
            }
        }
    }
 
    mx += (zero > one) ? zero : one;
}
 
/* here n is the total number of nodes after mapping */
 
/* running bfs on every node */
 
inline void bfs_full(int n){
    for(int i = 1 ; i <= n ; i++){
        if(vis[i] == 0) bfs(i);
    }
}
 
int main(){
    int T, k = 0;
    scanf("%d",&T);
 
    while(T--){
        memset(vis,0,sizeof(vis));
        memset(color,0,sizeof(color));
 
        for(int i = 0 ; i < MAXN ; i++) edges[i].clear();
 
        mx = 0;
 
        map <int,int> mp;
 
        int Assign = 1;
 
        int e; scanf("%d",&e);
 
        for(int i = 0 ; i < e ; i++){
            int u,v; scanf("%d %d",&u,&v);
            int x,y;
 
            if(mp.find(u) == mp.end()){
                mp[u] = Assign;
                Assign++;
            }
 
            x = mp[u];
 
            if(mp.find(v) == mp.end()){
                mp[v] = Assign;
                Assign++;
            }
 
            y = mp[v];
 
            edges[x].pb(y);
            edges[y].pb(x);
        }
 
        // here assign is the total number of nodes after mapping
 
        bfs_full(--Assign); // running bfs on every node , graph may be disconnected
 
        printf("Case %d: %d\n",++k,mx); // maximum of color 1 and 0
    }
 
    return 0;
}