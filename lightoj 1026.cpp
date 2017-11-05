#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
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

        bool operator < (const edge &ob) const{
            if(u == ob.u) return v < ob.v;
            return u < ob.u;
        }
};

const int MAXN = 10000 + 5;
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

            low[source] = (low[source] < low[adj]) ? low[source] : low[adj];

            if(low[adj] > disc[source]){ // strictly greater
                bridge.pb((source < adj ) ? edge(source,adj) : edge(adj,source));
            }
        }
        else{
            if(adj != parent[source]){
                low[source] = (low[source] < disc[adj]) ? low[source] : disc[adj]; // this is a back edge
            }
        }
    }
}

int main(){
    infile; outfile;
    int T,kase = 0;
    scanf("%d",&T);
    string input;
    while(T--){
        init();
        int nodes;
        scanf("%d",&nodes);
        getchar();
        for(int i = 0 ; i < nodes ; i++){
            getline(cin,input);
            stringstream ss(input);
            char a,b;
            int from; ss >> from; ss >> a;
            int m; ss >> m; ss >> b;
            //cout << "from " << from << " m " << m << endl;
            int to;
            while(ss >> to) { edges[from].pb(to); }
        }
        for(int i = 0 ; i < nodes ; i++){
            if(!visit[i]) dfs(i);
        }
        printf("Case %d:\n",++kase);
        if(!bridge.size()) printf("0 critical links\n");
        else{
            printf("%d critical links\n",bridge.size());
            sort(bridge.begin(),bridge.end());
            for(int i = 0 ; i < bridge.size() ; i++){
                printf("%d - %d\n",bridge[i].u,bridge[i].v);
            }
        }
    }
    return 0;
}
