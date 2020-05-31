#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>

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

const int MAXN = 50 + 5;
const int INF = 1e8 + 10;

class Graph{
    public:
        int nodesCount,edgesCount;
        int source,sink;
        vector < int > edge[MAXN];
        int nodeCapacity[MAXN];
        int parent[MAXN],currentPathCapacity[MAXN];
        int capacities[MAXN][MAXN],flowPassed[MAXN][MAXN];

        Graph(int nodesCount,int edgesCount){
            this -> nodesCount = nodesCount;
            this -> edgesCount = edgesCount;
            memset(capacities,0,sizeof(capacities));
            memset(flowPassed,0,sizeof(flowPassed));
        }

        inline void setSource(int source){
            this -> source = source;
        }

        inline void setSink(int sink){
            this -> sink = sink;
        }

        void takeNodesCapacity(){
            nodeCapacity[source] = nodeCapacity[sink] = INF;
            for(int i = 2 ; i <= nodesCount - 1 ; i++) {
                int x; scanf("%d",&x);
                nodeCapacity[i] = x;
            }
        }

        void takeInput(){
            for(int i = 0 ; i < edgesCount ; i++){
                int from,to,cap;
                scanf("%d %d %d",&from,&to,&cap);
                addEdge(from,to,cap);
            }
        }

        void addEdge(int from,int to,int capacity){
            edge[from].pb(to);
            edge[to].pb(from);
            int res = min(capacity,min(nodeCapacity[from],nodeCapacity[to]));
            capacities[from][to] = res;
            capacities[to][from] = res;
        }

        /*void printGraph(){
            for(int i = 1 ; i <= nodesCount ; i++){
                printf("%d: ",i);
                for(int j = 0 ; j < edge[i].size() ; j++){
                    printf("(%d,%d) ",edge[i][j],capacities[i][edge[i][j]]);
                }
                printf("\n");
            }
        }*/

        int bfs(int startNode,int endNode){
            memset(parent,-1,sizeof(parent));
            memset(currentPathCapacity,0,sizeof(currentPathCapacity));
            queue < int > q;
            q.push(startNode);
            currentPathCapacity[startNode] = INF;

            while(!q.empty()){
                int curNode = q.front();
                q.pop();

                for(int i = 0 ; i < edge[curNode].size() ; i++){
                    int adj = edge[curNode][i];
                    if(parent[adj] == -1){
                        if(capacities[curNode][adj] - flowPassed[curNode][adj] > 0){
                            parent[adj] = curNode;
                            currentPathCapacity[adj] = min(currentPathCapacity[curNode],capacities[curNode][adj] - flowPassed[curNode][adj]);
                            if(adj == endNode) {
                                return currentPathCapacity[endNode];
                            }
                            q.push(adj);
                        }
                    }
                }
            }

            return 0;
        }

        int EdmondKarp(int startNode,int endNode){
            int maxflow = 0;

            while(true){
                int flow = bfs(startNode,endNode);

                if(!flow) break;
                maxflow += flow;

                int curNode = endNode;

                while(curNode != startNode){
                    int prevNode = parent[curNode];
                    flowPassed[prevNode][curNode] += flow;
                    flowPassed[curNode][prevNode] -= flow;
                    curNode = prevNode;
                }

            }
            return maxflow;
        }
};

int main(){
    //infile; outfile;
    int T,kase = 0;
    scanf("%d",&T);
    while(T--){
        int m,w;
        scanf("%d %d",&m,&w);
        Graph g(m,w);
        g.setSource(1);
        g.setSink(m);
        g.takeNodesCapacity();
        g.takeInput();
        int maxFlow = g.EdmondKarp(g.source,g.sink);
        printf("Case %d: %d\n",++kase,maxFlow);
    }
    return 0;
}
