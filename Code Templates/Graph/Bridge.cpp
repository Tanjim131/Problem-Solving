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

class edge{
    public:
        int u;
        int v;

        edge(){}

        edge(int from,int to){
            this -> u = from;
            this -> v = to;
        }
};

const int MAXN = 100005;
vector < int > edges[MAXN];
vector < edge > bridge;

int parent[MAXN];
int visit[MAXN]; // visit array for DFS
int disc[MAXN]; // discovery time
int low[MAXN]; // low time

void init(){
    bridge.clear();
    for(int i = 0 ; i < MAXN ; i++){
        edges[i].clear();
        parent[i] = -1;
        visit[i] = 0;
        low[i] = disc[i] = 0;
    }
}

// Time complexity for finding articulation point/bridge - O(V+E) - same as DFS

void dfs(int source){
    static int t = 0; // counter for discovery time
    visit[source] = true;
    low[source] = disc[source] = (++t);
    int child = 0;

    for(int i = 0 ; i < edges[source].size() ; i++){
        int adj = edges[source][i];

        if(!visit[adj]){
            child++;
            parent[adj] = source;
            dfs(adj);

            low[source] = min(low[source],low[adj]);

            if(low[adj] > disc[source]){ // strictly greater
                bridge.pb(edge(source,adj));
            }
        }
        else{
            if(adj != parent[source]){
                low[source] = min(low[source],disc[adj]); // this is a back edge
            }
        }
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    init();
    for(int i = 0 ; i < m ; i++){
        int u,v; scanf("%d %d",&u,&v);
        edges[u].pb(v);
        edges[v].pb(u);
    }
    for(int i = 0 ; i < n ; i++){
        if(!visit[i]) dfs(i);
    }
    for(int i = 0 ; i < bridge.size() ; i++){
        cout << bridge[i].u << " " << bridge[i].v << endl;
    }
    return 0;
}

