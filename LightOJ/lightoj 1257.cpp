#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

#define LL long long
#define pb push_back
#define mp make_pair
#define PII pair < int , int >
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

class node{
    public:
        int index;
        int cost;

        node(){}

        node(int index,int cost){
            this -> index = index;
            this -> cost = cost;
        }
};

class Graph{
    public:
        int v,e; bool dir;
        int *visit,*dis1,*dis2;
        vector < node > *edge; // original graph

        Graph(bool d,int vertices){
            dir = d;
            v = vertices;
            e = vertices - 1;
            visit = new int[vertices + 5]();
            dis1 = new int[vertices + 5]();
            dis2 = new int[vertices + 5]();
            edge = new vector < node > [vertices + 5]();
            memset(visit,0,sizeof(visit));
            memset(dis1,0,sizeof(dis1));
            memset(dis2,0,sizeof(dis2));
        }

        void setVertices(int n) { v = n; }
        void setEdges(int n) { e = n; }

        void addEdge(int u,int v,int w){
                edge[u].pb(node(v,w));
                edge[v].pb(node(u,w));
        }

        void takeInput(){
            for(int i = 0 ; i < e ; i++){
                int from,to,weight;
                scanf("%d %d %d",&from,&to,&weight);
                addEdge(from,to,weight);
            }
        }

        void printGraph(){
            for(int i = 0 ; i < v ; i++){
                printf("%d: ",i);
                for(int j = 0 ; j < edge[i].size() ; j++){
                    printf("(%d,%d) ",edge[i][j].index,edge[i][j].cost);
                }
                printf("\n");
            }
        }


        void dfs1(int source){
            visit[source] = true;

            for(int i = 0 ; i < edge[source].size() ; i++){
                node adj = edge[source][i];
                if(!visit[adj.index]){
                    dis1[adj.index] = dis1[source] + adj.cost;
                    dfs1(adj.index);
                }
            }
        }

        void dfs2(int source){
            visit[source] = true;

            for(int i = 0 ; i < edge[source].size() ; i++){
                node adj = edge[source][i];
                if(!visit[adj.index]){
                    dis2[adj.index] = dis2[source] + adj.cost;
                    dfs2(adj.index);
                }
            }
        }

        void clr(){
            delete [] visit;
            visit = new int[v + 5]();
            memset(visit,0,sizeof(visit));
        }

        void call(){
            dfs1(0); // calling dfs from any node
                    // by calling dfs once we will get the node furthest from root
                    // this node is one of the end points of the tree diameter

            int mx = 0;
            int index = -1;

            for(int i = 0 ; i < v ; i++){
                if(mx < dis1[i]){
                    mx = dis1[i];
                    index = i;
                }
            }

            dis1[index] = 0;
            clr();
            dfs1(index); // calling dfs from this node will get us the second end point the tree diameter

            mx = 0;
            index = -1;

            for(int i = 0 ; i < v ; i++){
                if(mx < dis1[i]){
                    mx = dis1[i];
                    index = i;
                }
            }

            clr();
            dfs2(index); // calling third dfs to compute the distances of other nodes from this second end point of tree diameter
        }
};

int main(){
    //infile; outfile;
    int T,kase = 0; scanf("%d",&T);
    while(T--){
        int v; scanf("%d",&v);
        Graph g(true,v);
        g.takeInput();
        //g.printGraph();
        g.call();
        printf("Case %d:\n",++kase);
        for(int i = 0 ; i < v ; i++){
            printf("%d\n",max(g.dis1[i],g.dis2[i]));
        }
    }
    return 0;
}

