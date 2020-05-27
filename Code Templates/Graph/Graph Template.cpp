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

        bool operator < (const node &ob) const{
            return cost > ob.cost; // min heap, change to < for max heap
        }
};

class Graph{
    public:
        int v,e; bool dir;
        int *visit,*dist,*parent;
        vector < node > *edge;

        Graph(bool d,int vertices,int edges){
            this -> dir = d;
            this -> v = vertices;
            this -> e = edges;
            this -> parent = new int[vertices + 5]();
            this -> visit = new int[vertices + 5]();
            this -> dist = new int[vertices + 5]();
            this -> edge = new vector < node > [vertices + 5]();
        }

        void setVertices(int n) { v = n; }
        void setEdges(int n) { e = n; }

        void addEdge(int u,int v,int w){
            if(dir){
                edge[u].pb(node(v,w));
            }
            else{
                edge[u].pb(node(v,w));
                edge[v].pb(node(u,w));
            }
        }

        void takeInput(){
            for(int i = 0 ; i < e ; i++){
                int from,to,weight;
                scanf("%d %d %d",&from,&to,&weight);
                addEdge(from,to,weight);
            }
        }

        void printGraph(){
            for(int i = 0 ; i < v ; i++){ // change v to 1 if vertex numbering is from 1 to n
                printf("%d: ",i);
                for(int j = 0 ; j < edge[i].size() ; j++){
                    printf("(%d,%d) ",edge[i][j].index,edge[i][j].cost);
                }
                printf("\n");
            }
        }
};

int main(){
    //infile; outfile;
    //int T,kase = 0; scanf("%d",&T);
    //while(T--){
        int v,e; scanf("%d %d",&v,&e);
        Graph g(true,v,e);
        g.takeInput();
        g.printGraph();
    //}
    return 0;
}

