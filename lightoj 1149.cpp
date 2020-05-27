#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
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

const int MAXN = 200 + 5;
const int INF = 1e9;

int setA[100 +5],setB[100 + 5];
int n,m;

class Graph{
    public:
        int nodesCount;
        int source,sink;
        vector < int > edge[MAXN];
        int parent[MAXN],currentPathCapacity[MAXN];
        int capacities[MAXN][MAXN],flowPassed[MAXN][MAXN];

        Graph(int nodesCount){
            this -> nodesCount = nodesCount;
            memset(capacities,0,sizeof(capacities));
            memset(flowPassed,0,sizeof(flowPassed));
        }

        inline void setSource(int source){
            this -> source = source;
        }

        inline void setSink(int sink){
            this -> sink = sink;
        }

        void takeInput(){
            for(int i = 0 ; i < n ; i++){
                // for every integer in setA look multiples in setB
                for(int j = 0 ; j < m ; j++){
                    if(setB[j] % setA[i] == 0){
                        // a match
                        addEdge(i + 1,n + j + 1,1);
                    }
                }
            }

            for(int i = 0 ; i < n ; i++){
                // add an edge from the source to every integer in setA
                addEdge(source,i + 1,1); // with capacity 1
            }

            for(int i = 0 ; i < m ; i++){
                // add an edge from every node in setB to sink with capacity 1
                addEdge(n + i + 1,sink,1);
            }
        }

        inline void addEdge(int from,int to,int capacity){
            edge[from].pb(to);
            edge[to].pb(from); // adding the negative edge
            capacities[from][to] = capacity;
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
    //infile; outfile;
    int T,kase = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++) scanf("%d",&setA[i]);
        scanf("%d",&m);
        for(int i = 0 ; i < m ; i++) scanf("%d",&setB[i]);
        Graph g(n + m + 2); // 0 is the source, n + m + 1 is the sink
        g.setSource(0);
        g.setSink(n + m + 1);
        g.takeInput();
        int maxFlow = g.EdmondKarp(g.source,g.sink);
        printf("Case %d: %d\n",++kase,maxFlow);
    }
    return 0;
}


