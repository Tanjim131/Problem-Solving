#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>
 
using namespace std;
 
const int MAXN = 105;
 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define LL long long
 
vector<pii>edges[MAXN];
int vis[MAXN];
 
int prim(int source){
    memset(vis,0,sizeof(vis));
    priority_queue < pii, vector <pii>, greater <pii> > pq;
    int mincost = 0;
    pq.push(mp(0,source)); /* because in priority_queue the sorting is based on first element */
                            /* here we are sorting the edges based on their weights */
 
    pii top; int y;
 
    while(!pq.empty()){
        top = pq.top();
        pq.pop();
 
        if(vis[top.second] == true) continue; // cycle checking
 
        mincost += top.first;
 
        vis[top.second] = true;
 
        for(int i = 0 ; i < edges[top.second].size() ; i++){
            y = edges[top.second][i].second;
            if(vis[y] == false) pq.push(edges[top.second][i]);
 
        }
    }
 
    return mincost;
}
 
void dfs(int source){
    vis[source] = 1;
    for(int i = 0 ; i < edges[source].size() ; i++){
        if(vis[edges[source][i].second] == 0){
            dfs(edges[source][i].second);
        }
    }
}
 
int connected(int nodes){
    memset(vis,0,sizeof(vis));
    int tot = 0;
    for(int i = 0 ; i < nodes ; i++){
        if(vis[i] == 0){
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
        int roads; scanf("%d",&roads);
 
        for(int i = 0 ; i < MAXN ; i++) edges[i].clear();
 
        map<string,int>m;
 
        string a,b; int x,y,w,assign = 0;
 
        for(int i = 0 ; i < roads ; i++){
            cin >> a >> b; scanf("%d",&w);
 
            if(m.find(a) == m.end()) m[a] = assign++;
            if(m.find(b) == m.end()) m[b] = assign++;
 
            x = m[a];
            y = m[b];
 
            edges[x].pb(mp(w,y));
            edges[y].pb(mp(w,x));
        }
 
        assign--;
 
        int ret = connected(assign);
 
        if(!ret) { printf("Case %d: Impossible\n",++k); continue; }
 
        int ans = prim(0);
 
        printf("Case %d: %d\n",++k,ans);
    }
 
    return 0;
}
 