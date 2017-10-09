#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
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

const int MAXN = 205;

class node{
    public:
        int index;
        int cost;

        node(){}

        node(int u,int c){
            index = u;
            cost = c;
        }

        bool operator < (const node &ob) const{
            return cost > ob.cost; // min heap (priority_queue)
        }
};

class Graph{
    public:
        int v,e; bool dir;
        int distance[MAXN],parent[MAXN];
        vector < node > edge[MAXN];


        Graph(bool d) {dir = d;}

        Graph(bool d,int vertices,int edges){
            dir = d;
            v = vertices;
            e = edges;
        }

        void setVertices(int n) { v = n; }
        void setEdges(int n) { e = n; }

        void addEdge(int u,int v,int w){
            if(dir) edge[u].pb(node(v,w)); // directed graph
            else{
                edge[u].pb(node(v,w));
                edge[v].pb(node(u,w)); // undirected graph
            }
        }

        void takeinput(){
            for(int i = 0 ; i < e ; i++){
                int from,to,weight;
                scanf("%d %d %d",&from,&to,&weight);
                addEdge(from,to,weight);
            }
        }

        void printGraph(){
            for(int i = 1 ; i <= v ; i++){
                printf("%d: ",i);
                for(int j = 0 ; j < edge[i].size() ; j++){
                    printf("(%d,%d) ",edge[i][j].index,edge[i][j].cost);
                }
                printf("\n");
            }
        }

        bool bellmanford(int source){
            memset(distance,63,sizeof(distance));
            memset(parent,-1,sizeof(parent));

            distance[source] = 0;
            parent[source] = -2;

            for(int k = 1 ; k <= v - 1 ; k++){
                for(int i = 1 ; i <= v ; i++){
                    for(int j = 0 ; j < edge[i].size() ; j++){
                       node qq = edge[i][j];
                       if(distance[i] + qq.cost < distance[qq.index]){
                            //printf("Going from %d to %d with cost %d\n",i,qq.index,qq.cost);
                            distance[qq.index] = distance[i] + qq.cost;
                            parent[qq.index] = i;
                       }
                    }
                }
            }

            //for(int i = 1 ; i <= v ; i++) printf("%d ",distance[i]);
            //printf("\n");

            //for(int i = 1 ; i <= v ; i++) printf("%d ",parent[i]);
            //printf("\n");

            bool negCycle = false;

            for(int i = 1 ; i <= v ; i++){
                for(int j = 0 ; j < edge[i].size() ; j++){
                    node qq = edge[i][j];
                    if(distance[i] + qq.cost < distance[qq.index]){
                        negCycle = true;
                        break;
                    }
                }
            }

            return negCycle;
        }



        bool findParent(int destination){
            bool isParent = false;
            for(int i = 1 ; i <= v ; i++){
                if(parent[destination] == -2){
                    isParent = true;
                    break;
                }
                else if(parent[destination] == -1) break;
                destination = parent[destination];
            }
            return isParent;
        }

};

int busy[MAXN];

int main(){
    //infile; outfile;
    int T; scanf("%d",&T);
    int kase = 0;
    while(T--){
        int v; scanf("%d",&v);
        Graph g(true); g.setVertices(v);

        for(int i = 1 ; i <= v ; i++){
            scanf("%d",&busy[i]);
        }

        int e; scanf("%d",&e);
        g.setEdges(e);

        for(int i = 0 ; i < e ; i++){
            int u,v; scanf("%d %d",&u,&v);
            int w = busy[v] - busy[u];
            g.addEdge(u,v,w * w * w);
        }

        //g.printGraph();

        int query; scanf("%d",&query);
        printf("Case %d:\n",++kase);
        bool res = g.bellmanford(1);
        while(query--){
            int x; scanf("%d",&x);
            if(g.distance[x] < 3 || !g.findParent(x)) printf("?\n");
            else printf("%d\n",g.distance[x]);
        }
    }
    return 0;
}


