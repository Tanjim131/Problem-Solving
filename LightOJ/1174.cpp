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
#define infile(f) freopen(f,"r",stdin)
#define outfile(f) freopen(f,"w",stdout)

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

const int MAXN = 100 + 5;
vector < int > graph[MAXN];
int dist1[MAXN],visit1[MAXN];
int dist2[MAXN],visit2[MAXN];

inline void init(){
    for(int i = 0 ; i < MAXN ; i++){
        graph[i].clear();
    }
}

inline void addEdge(int from,int to){
    graph[from].pb(to);
    graph[to].pb(from);
}

void bfs1(int source){ // run bfs from source
    memset(dist1,0,sizeof(dist1));
    memset(visit1,0,sizeof(visit1));

    queue < int > q;
    q.push(source);
    visit1[source] = true;
    dist1[source] = 0;

    while(!q.empty()){
        source = q.front();
        q.pop();

        for(int i = 0 ; i < graph[source].size() ; i++){
            int adj = graph[source][i];

            if(!visit1[adj]){
                visit1[adj] = true;
                dist1[adj] = dist1[source] + 1;
                q.push(adj);
            }
        }
    }
}

int bfs2(int destination){ // run bfs from destination
    memset(dist2,0,sizeof(dist2));
    memset(visit2,0,sizeof(visit2));

    queue < int > q;
    q.push(destination);
    visit2[destination] = true;
    dist2[destination] = 0;

    while(!q.empty()){
        destination = q.front();
        q.pop();

        for(int i = 0 ; i < graph[destination].size() ; i++){
            int adj = graph[destination][i];

            if(!visit2[adj]){
                visit2[adj] = true;
                dist2[adj] = dist2[destination] + 1;
                q.push(adj);
            }
        }
    }
}

int ret(int nodes,int source,int destination){
    int ans = dist1[destination];

    for(int i = 0 ; i < nodes ; i++){
        if(i != source && i != destination){
            ans = max(ans,dist1[i] + dist2[i]);
        }
    }

    return ans;
}

int main(){
    int T,kase = 0;
    scanf("%d",&T);
    while(T--){
        init();
        int N,M;
        scanf("%d %d",&N,&M);
        for(int i = 0 ; i < M ; i++){
            int from,to;
            scanf("%d %d",&from,&to);
            addEdge(from,to);
        }
        int source,destination;
        scanf("%d %d",&source,&destination);
        bfs1(source);
        bfs2(destination);
        printf("Case %d: %d\n",++kase,ret(N,source,destination));
    }
    return 0;
}


