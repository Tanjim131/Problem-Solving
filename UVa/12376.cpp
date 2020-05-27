#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair < int , int >
#define pb push_back
#define mp make_pair

const int MAXN = 105;
vector < pii > edges[MAXN];
int cost[MAXN];
int n;

bool cmp(pii a,pii b){
    return a.first > b.first;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,k = 0;
    scanf("%d",&T);
    while(T--){
        int m;
        for(int i = 0 ; i < MAXN ; i++) edges[i].clear();
        scanf("%d %d",&n,&m);
        for(int i = 0 ; i < n ; i++) scanf("%d",&cost[i]);
        for(int i = 0 ; i < m ; i++){
            int x,y; scanf("%d %d",&x,&y);
            edges[x].pb(mp(cost[y],y));
        }
        for(int i = 0 ; i < n ; i++) sort(edges[i].begin(),edges[i].end(),cmp);
        int counter = 0;
        int node = 0;
        while(!edges[node].empty()){
            counter += edges[node][0].first;
            node = edges[node][0].second;
        }
        printf("Case %d: %d %d\n",++k,counter,node);
    }
    return 0;
}
