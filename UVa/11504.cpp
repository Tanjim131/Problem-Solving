#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <map>

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

//Basic Idea:
// First do a topsort to determine from where you should run our dfs/bfs
// after sorting the nodes based on their finishing time, run the second bfs/dfs

class node{
    public:
        int index;
        int t;

        node(){}

        node(int index,int t){
            this -> index = index;
            this -> t = t;
        }

        bool operator < (const node &ob) const{
            return t > ob.t;
        }
};

class Graph{
    public:
        int v,e; bool dir;
        int *visit;
        node *finish; // finishing time
        vector < int > *edge; // original graph

        Graph(bool d,int vertices,int edges){
            dir = d;
            v = vertices;
            e = edges;
            visit = new int[vertices + 5]();
            finish = new node[vertices + 5]();
            edge = new vector < int > [vertices + 5]();
            memset(visit,0,sizeof(visit));
            memset(finish,0,sizeof(finish));
        }

        void setVertices(int n) { v = n; }
        void setEdges(int n) { e = n; }

        void addEdge(int u,int v){
            if(dir){
                edge[u].pb(v);
            }
            else{
                edge[u].pb(v);
                edge[v].pb(u);
            }
        }

        void takeInput(){
            for(int i = 0 ; i < e ; i++){
                int from,to;
                scanf("%d %d",&from,&to);
                addEdge(from,to);
            }
        }

        void printGraph(){
            for(int i = 1 ; i <= v ; i++){
                printf("%d: ",i);
                for(int j = 0 ; j < edge[i].size() ; j++){
                    printf("(%d) ",edge[i][j]);
                }
                printf("\n");
            }
        }

        void dfs1(int source){
            static int ti = 0;
            ++ti;
            visit[source] = true;

            for(int i = 0 ; i < edge[source].size() ; i++){
                int adj = edge[source][i];

                if(!visit[adj]){
                    dfs1(adj);
                }
            }

            finish[source].index = source;
            finish[source].t = (++ti);
        }

        void dfs2(int source){
            visit[source] = true;
            for(int i = 0 ; i < edge[source].size() ; i++){
                int adj = edge[source][i];
                if(!visit[adj]) dfs2(adj);
            }
        }

        void topsort(){
            for(int i = 1 ; i <= v ; i++){
                if(!visit[i]) dfs1(i);
            }

            sort(finish + 1,finish + v + 1);
        }

        int res(){
            delete [] visit;
            visit = new int [v + 5]();
            memset(visit,0,sizeof(visit));

            int ret = 0;
            for(int i = 1 ; i <= v ; i++){
                int vertex = finish[i].index;
                if(!visit[vertex]){
                    ret++;
                    dfs2(vertex);
                }
            }
            return ret;
        }
};

int main(){
    //infile; outfile;
    int T; scanf("%d",&T);
    while(T--){
        int v,e; scanf("%d %d",&v,&e);
        Graph g(true,v,e);
        g.takeInput();
        //g.printGraph();
        g.topsort();
        printf("%d\n",g.res());
    }
    return 0;
}

