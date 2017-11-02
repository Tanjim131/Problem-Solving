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



// Main Idea:
// Split the Graph into Strongly Connected Components using Tarjan's Algorithm
// Run Bellman Ford Algorithm on each of the S.C.Cs
// If a S.C.C contains negative cycle then mark it
// Run B.F.S from other nodes which are not included in the S.C.Cs

const int MAXN = 1000 + 5;

class node{
    public:
        int index;
        int cost;

        node(){}

        node(int u,int c){
            index = u;
            cost = c;
        }
};

class Graph{
    public:
        int v,e; bool dir;
        int distance[MAXN],parent[MAXN],visit[MAXN],mark[MAXN]; // distance and parent for bellman ford
        int disc[MAXN],low[MAXN]; // discovery time and low time
        bool stackMember[MAXN]; // to check whether a node is still on the stack
        vector < node > edge[MAXN]; // original graph
        stack < int > s; // stack for DFS traversal

        Graph(bool d){
            dir = d;
            memset(visit,0,sizeof(visit));
            memset(parent,-1,sizeof(parent));
            memset(distance,63,sizeof(distance));
            memset(disc,0,sizeof(disc));
            memset(low,0,sizeof(low));
            memset(stackMember,0,sizeof(stackMember));
            memset(mark,0,sizeof(mark));
        }

        Graph(bool d,int vertices,int edges){
            dir = d;
            v = vertices;
            e = edges;
            memset(visit,0,sizeof(visit));
            memset(parent,-1,sizeof(parent));
            memset(distance,63,sizeof(distance));
            memset(disc,0,sizeof(disc));
            memset(low,0,sizeof(low));
            memset(stackMember,0,sizeof(stackMember));
            memset(mark,0,sizeof(mark));
        }

        void setVertices(int n) { v = n; }
        void setEdges(int n) { e = n; }

        void addEdge(int u,int v,int w){
            if(dir){
                edge[u].pb(node(v,w)); // directed graph
            }
            else{
                edge[u].pb(node(v,w));
                edge[v].pb(node(u,w)); // undirected graph
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
            for(int i = 0 ; i < v ; i++){
                printf("%d: ",i);
                for(int j = 0 ; j < edge[i].size() ; j++){
                    printf("(%d,%d) ",edge[i][j].index,edge[i][j].cost);
                }
                printf("\n");
            }
        }

        bool BellmanFord(vector < int > &vec){
            int len = vec.size();
            int source = vec[len - 1];
            distance[source] = 0;

            for(int k = 1 ; k < len ; k++){
                for(int i = 0 ; i < vec.size() ; i++){
                    for(int j = 0 ; j < edge[vec[i]].size() ; j++){
                        node qq = edge[vec[i]][j];
                        if(distance[qq.index] > distance[vec[i]] + qq.cost){
                            distance[qq.index] = distance[vec[i]] + qq.cost;
                        }
                    }
                }
            }

            for(int i = 0 ; i < vec.size() ; i++){
                for(int j = 0 ; j < edge[vec[i]].size() ; j++){
                    node qq = edge[vec[i]][j];

                    if(distance[qq.index] > distance[vec[i]] + qq.cost){
                        vector < int > :: iterator it = find(vec.begin(),vec.end(),qq.index);
                        if(it != vec.end()) return true;
                        // It can so happen that the updated node is not in the S.C.C. Handling that with a simple check
                    }
                }
            }
            return false;
        }

        void dfsUtil(int source){
            static int ti = 0;
            disc[source] = low[source] = (++ti);
            visit[source] = true;
            s.push(source);
            stackMember[source] = true;

            for(int i = 0 ; i < edge[source].size() ; i++){
                int adj = edge[source][i].index;

                if(!visit[adj]){
                    dfsUtil(adj);
                    low[source] = min(low[source],low[adj]);
                }
                else if(stackMember[adj]){
                    low[source] = min(low[source],disc[adj]);
                }
            }


            vector < int > vv; // vector for storing the S.C.Cs

            int w = 0;
            // Got an SCC
            if(disc[source] == low[source]){
                while(s.top() != source){
                    w = (int) s.top();
                    //cout << w << " ";
                    vv.pb(w);
                    stackMember[w] = false;
                    s.pop();
                }
                w = (int) s.top();
                //cout << w << " n";
                vv.pb(w);
                stackMember[w] = false;
                s.pop();

                if((int) vv.size() > 1 && BellmanFord(vv)){
                    for(int r = 0 ; r < (int) vv.size() ; r++) mark[vv[r]] = true;
                    //for(auto val : vv) works fine but using it given Compilation Error in LightOJ
                }
            }
        }

        void TarjanSCC(){
            for(int i = 0 ; i < v ; i++){
                if(!visit[i]) dfsUtil(i);
            }
        }

        void bfs(int source){
            if(mark[source]) return ;

            memset(visit,0,sizeof(visit));
            memset(parent,-1,sizeof(parent));
            queue < int > q;
            q.push(source);

            while(!q.empty()){
                source = q.front();
                q.pop();

                visit[source] = true;

                for(int i = 0 ; i < edge[source].size() ; i++){
                    int rr = edge[source][i].index;
                    if(!visit[rr]){
                        if(mark[rr]){
                            // reached a node within a scc with negative cycle
                            while(1){
                                mark[source] = true;
                                if(parent[source] == -1) break;
                                source = parent[source];
                                // now backtracking to the node from where the b.f.s was ran
                            }

                            return ;
                        }
                        else {
                            parent[rr] = source;
                            q.push(rr);
                        }
                    }
                }
            }
        }

        bool res(){
            for(int i = 0 ; i < v ; i++){
                if(!mark[i]) bfs(i);
            }

            for(int i = 0 ; i < v ; i++){
                if(mark[i]) return true;
            }

            return false;
        }
};


int main(){
    //infile; outfile;
    int T,kase = 0;
    scanf("%d",&T);
    while(T--){
        int v,e; scanf("%d %d",&v,&e);
        Graph g(true,v,e);
        g.takeInput();
        //g.printGraph();
        g.TarjanSCC();
        if(g.res()){
            printf("Case %d:",++kase);
            for(int i = 0 ; i < v ; i++){
                if(g.mark[i]) printf(" %d",i);
            }
            printf("\n");
        }
        else printf("Case %d: impossible\n",++kase);
    }
    return 0;
}
