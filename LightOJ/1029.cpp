#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
 
using namespace std;
 
const int MAXN = 105;
 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define LL long long
 
vector<pii>edges[MAXN];
int vis[MAXN];
 
LL prim_best(int source){
    memset(vis,false,sizeof(vis));
    priority_queue < pii, vector <pii>, greater <pii> > pq;
    LL mincost = 0;
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
 
LL prim_worst(int source){
    memset(vis,false,sizeof(vis));
    priority_queue < pii, vector <pii>, less<pii> > pq;
    LL mincost = 0;
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
 
LL gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a % b);
}
 
int main(){
    int T,k = 0;
    scanf("%d",&T);
 
    while(T--){
        int house; scanf("%d",&house);
 
        int a,b,w;
 
        for(int i = 0 ; i < MAXN ; i++) edges[i].clear();
 
        while(scanf("%d %d %d",&a,&b,&w) == 3){
            if(a == 0 && b == 0 && w == 0) break;
 
            edges[a].pb(mp(w,b));
            edges[b].pb(mp(w,a));
        }
 
        LL best = prim_best(0);
        LL worst = prim_worst(0);
 
        LL tot = best + worst;
 
        if(tot & 1) printf("Case %d: %lld/2\n",++k,tot);
        else{
            tot >>= 1;
            printf("Case %d: %lld\n",++k,tot);
        }
    }
 
    return 0;
}