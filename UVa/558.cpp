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

const int MAXN = 1005;

struct node{
    int index;
    int cost;

    node(){}

    node(int u,int c){
        index = u;
        cost = c;
    }
};

vector < node > edges[MAXN];
int dist[MAXN];
int n,m;

bool bellmanford(int source){
    for(int i = 0 ; i < n ; i++) dist[i] = 5000;
    dist[source] = 0;

    for(int k = 0 ; k < n - 1 ; k++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < edges[i].size() ; j++){
                node qq = edges[i][j];
                if(dist[i] + qq.cost < dist[qq.index]){
                    dist[qq.index] = dist[i] + qq.cost;
                }
            }
        }
    }

    bool negCycle = false;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < edges[i].size() ; j++){
            node qq = edges[i][j];
            if(dist[i] + qq.cost < dist[qq.index]){
                negCycle = true;
                break;
            }
        }
    }

    return negCycle;
}

void clr(){
    for(int i = 0 ; i < n ; i++) edges[i].clear();
}

int main(){
    //infile;outfile;
    int c; scanf("%d",&c);
    while(c--){
        clr();
        scanf("%d %d",&n,&m);
        for(int i = 0 ; i < m ; i++){
            int from,to,weight;
            scanf("%d %d %d",&from,&to,&weight);
            edges[from].pb(node(to,weight));
        }

        if(bellmanford(0)) printf("possible\n");
        else printf("not possible\n");
    }
    return 0;
}


