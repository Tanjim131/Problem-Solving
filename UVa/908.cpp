#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <sstream>

using namespace std;

#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair < int , int >
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction



struct node{
    int index;
    int cost;

    node(){}

    node(int u,int c){
        index = u;
        cost = c;
    }

    bool operator < (const node &obj) const{
        return cost > obj.cost;
    }
};

const int MAXN = 1000005;
bool visit[MAXN];
vector < node > edges[MAXN];
int n;

LL prim(int source){
    priority_queue < node > pq;
    pq.push(node(source,0));
    LL mincost = 0;
    memset(visit,0,sizeof(visit));
    while(!pq.empty()){
        node top = pq.top();
        pq.pop();

        if(visit[top.index]) continue;

        mincost += top.cost;

        visit[top.index] = true;

        for(int i = 0 ; i < edges[top.index].size() ; i++){
            node to = edges[top.index][i];
            if(!visit[to.index]){
                pq.push(node(to.index,to.cost));
            }
        }
    }

    return mincost;
}

void clr(){
    for(int i = 1 ; i <= n; i++){
        edges[i].clear();
    }
}

int main(){
    //infile; outfile;
    bool f = false;
    while(scanf("%d",&n) != EOF){
        if(f) printf("\n");
        f = true;
        clr();
        LL ffcost = 0;
        for(int i = 1 ; i <= n - 1 ; i++){
            int u,v,w; scanf("%d %d %d",&u,&v,&w);
            edges[u].pb(node(v,w));
            edges[v].pb(node(u,w));
            ffcost += w;
        }

        int k; scanf("%d",&k);
        for(int i = 0 ; i < k ; i++){
            int u,v,w; scanf("%d %d %d",&u,&v,&w);
            edges[u].pb(node(v,w));
            edges[v].pb(node(u,w));
        }

        int m; scanf("%d",&m);
        for(int i = 0 ; i < m ; i++){
            int u,v,w; scanf("%d %d %d",&u,&v,&w);
        }


        LL cc = prim(1);
        printf("%lld\n%lld\n",ffcost,cc);
    }

    return 0;
}
