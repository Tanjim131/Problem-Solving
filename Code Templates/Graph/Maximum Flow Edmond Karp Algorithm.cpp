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
#define PII pair < int , int >
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

const int MAXN = 100 + 5;
const int INF = 1e9;

class Graph{
    public:
        int nodesCount,edgesCount;
        int source,sink;
        vector < int > edge[MAXN];
        vector < int > originalGraph[MAXN];
        int parent[MAXN],currentPathCapacity[MAXN],visit[MAXN];
        int capacities[MAXN][MAXN],flowPassed[MAXN][MAXN];

        Graph(int nodesCount,int edgesCount){
            this -> nodesCount = nodesCount;
            this -> edgesCount = edgesCount;
            memset(capacities,0,sizeof(capacities));
            memset(flowPassed,0,sizeof(flowPassed));
        }

        void setSource(int source){
            this -> source = source;
        }

        void setSink(int sink){
            this -> sink = sink;
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
            edge[to].pb(from); // adding the negative edge
            capacities[from][to] = capacity;
            //printf("Adding edge %d with %d\n",from,to);
            originalGraph[from].pb(to);
        }

        void printGraph(){
            for(int i = 0 ; i < nodesCount ; i++){
                printf("%d: ",i);
                for(int j = 0 ; j < edge[i].size() ; j++){
                    printf("(%d,%d) ",edge[i][j],capacities[i][edge[i][j]]);
                }
                printf("\n");
            }
        }

        void dfs(int source){
            visit[source] = true;
            for(int i = 0 ; i < originalGraph[source].size() ; i++){
                int adj = originalGraph[source][i];
                if(!visit[adj] && (capacities[source][adj] - flowPassed[source][adj] > 0)) dfs(adj);
            }
        }

        void MinimumCut(){
            memset(visit,0,sizeof(visit));
            dfs(source);

            printf("Minimum Cut(s) are:\n");
            for(int i = 0 ; i < nodesCount ; i++){
                for(int j = 0 ; j < originalGraph[i].size() ; j++){
                    int adj = originalGraph[i][j];
                    if(visit[i] && !visit[adj]){
                        printf("%d - %d with Capacity %d\n",i,adj,capacities[i][adj]);
                    }
                }
            }
        }

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
                            if(adj == endNode) return currentPathCapacity[endNode];
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
    int n,m;
    scanf("%d %d",&n,&m);
    Graph g(n,m);
    g.takeInput();
    int source,sink;
    scanf("%d %d",&source,&sink);
    g.setSource(source);
    g.setSink(sink);
    g.printGraph();
    int maxFlow = g.EdmondKarp(source,sink);
    printf("Maximum Flow in the Flow Network is %d\n",maxFlow);
    g.MinimumCut();
    return 0;
}

