#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>
 
using namespace std;
 
const int MAXN = 55;
 
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
        int n; scanf("%d",&n);
        int tot = 0;
 
        for(int i = 0 ; i < MAXN ; i++) edges[i].clear();
 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                int val; scanf("%d",&val);
                if(val != 0){
                    edges[i].pb(mp(val,j));
                    edges[j].pb(mp(val,i));
                    tot += val;
                }
            }
        }
 
        int ret = connected(n);
 
        if(!ret) { printf("Case %d: -1\n",++k); continue; }
 
        int ans = prim(0);
 
        printf("Case %d: %d\n",++k,tot - ans);
    }
 
    return 0;
}