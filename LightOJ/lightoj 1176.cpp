#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
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

const int MAXN = 50 + 10;
const int INF = 1e8 + 10;

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

        void setSource(int source){
            this -> source = source;
        }

        void setSink(int sink){
            this -> sink = sink;
        }

        void addEdge(int from,int to,int capacity){
            edge[from].pb(to);
            edge[to].pb(from); // adding the negative edge
            capacities[from][to] = capacity;
        }

        /*void printGraph(){
            for(int i = 0 ; i < nodesCount ; i++){
                printf("%d: ",i);
                for(int j = 0 ; j < edge[i].size() ; j++){
                    printf("(%d) ",edge[i][j]);
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

void process(map < string , int > &m){
    m.insert(mp("XXL",1));
    m.insert(mp("XL",2));
    m.insert(mp("L",3));
    m.insert(mp("M",4));
    m.insert(mp("S",5));
    m.insert(mp("XS",6));
}

int main(){
    //infile;
    //outfile;
    int T,kase = 0;
    scanf("%d",&T);
    map < string , int > m; process(m);
    while(T--){
        int color,people;
        scanf("%d %d",&color,&people);
        int tNodes = people + 8;
        // calculation : number of people (people) + t-shirt sizes (6) + super-source (1) + super-sink (1)
        Graph g(tNodes);
        g.setSource(0);
        g.setSink(tNodes - 1);
        // setting source and sink

        // taking input
        char a[10],b[10];
        for(int i = 0 ; i < people ; i++){
            scanf("%s %s",a,b);
            g.addEdge(i + 7,m[a],1);
            g.addEdge(i + 7,m[b],1);
        }
        // input taking done

        // setting up super-source

        for(int i = 0 ; i < people ; i++){
            g.addEdge(0,i + 7,1);
        }

        // super-source done

        // setting up super-sink

        for(int i = 1 ; i <= 6 ; i++){
            g.addEdge(i,tNodes - 1,color);
        }

        // super-sink done

        //g.printGraph();

        int maxFlow = g.EdmondKarp(g.source,g.sink);
        //cout << "maxFlow " << maxFlow  << " people " << people << endl;
        if(maxFlow == people) printf("Case %d: YES\n",++kase);
        else printf("Case %d: NO\n",++kase);
    }
    return 0;
}
