#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>
 
using namespace std;
 
const int MAXN = 10005;
 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define LL long long
#define MAX_VALUE 15000
 
vector<pii>edges[MAXN];
int vis_mst[MAXN]; // visit array for minimum spanning tree
int vis_dfs[MAXN]; // visit array for dfs
int cost,component; // total cost & number of airports
 
int prim(int source){
    priority_queue < pii, vector <pii>, greater <pii> > pq;
    int mincost = 0,tmpair = 0;
    pq.push(mp(0,source)); /* because in priority_queue the sorting is based on first element */
                            /* here we are sorting the edges based on their weights */
 
    pii top; int y;
 
    while(!pq.empty()){
        top = pq.top();
        pq.pop();
 
        if(vis_mst[top.second] == true) continue; // cycle checking
 
        mincost += top.first;
 
        vis_mst[top.second] = true;
 
        for(int i = 0 ; i < edges[top.second].size() ; i++){
            y = edges[top.second][i].second;
            if(vis_mst[y] == false) pq.push(edges[top.second][i]);
        }
    }
 
    return mincost;
}
 
void dfs(int source){
    vis_dfs[source] = 1;
    for(int i = 0 ; i < edges[source].size() ; i++){
        if(vis_dfs[edges[source][i].second] == 0){
            dfs(edges[source][i].second);
        }
    }
}
 
void connected(int nodes){
    for(int i = 1 ; i <= nodes ; i++){
        if(vis_dfs[i] == 0){
            dfs(i);
            cost += prim(i);
            component++;
        }
    }
}
 
int main(){
    //freopen("lightoj1059in.txt","r",stdin);
    //freopen("lightoj1059out.txt","w",stdout);
    int T,k = 0;
    scanf("%d",&T);
 
    while(T--){
        int N,M,A; // N - number of locations , M - number of edges , A - cost of an airport
        scanf("%d %d %d",&N,&M,&A);
 
        //Initialize
 
        cost = 0,component = 0;
        for(int i = 0 ; i < MAXN ; i++) edges[i].clear();
        memset(vis_mst,0,sizeof(vis_mst));
        memset(vis_dfs,0,sizeof(vis_dfs));
 
        // Initialization done
 
        for(int i = 0 ; i < M ; i++){
            int x,y,w; scanf("%d %d %d",&x,&y,&w);
 
            if(w < A){ // w is strictly less than A
                edges[x].pb(mp(w,y));
                edges[y].pb(mp(w,x));
            }
        }
 
        connected(N);
 
        cost += component * A;
 
        printf("Case %d: %d %d\n",++k,cost,component);
    }
 
    return 0;
}