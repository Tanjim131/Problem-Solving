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
#define pii pair < int , int >
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

const int MAXN = 10000 + 5;
vector < int > edges[MAXN];

int parent[MAXN];
int visit[MAXN]; // visit array for DFS
int disc[MAXN]; // discovery time
int low[MAXN]; // low time
int AP[MAXN]; // list of articulation points

void init(int n){
    for(int i = 0 ; i <= n ; i++){
        edges[i].clear();
        parent[i] = -1;
        visit[i] = AP[i] = 0;
        low[i] = disc[i] = 0;
    }
}

// Time complexity for finding articulation point - O(V+E) - same as DFS

int dfs(int source){
    static int t = 0; // counter for discovery time
    visit[source] = true;
    low[source] = disc[source] = (++t);
    int child = 0; // actually counting the subtree of the root

    for(int i = 0 ; i < edges[source].size() ; i++){
        int adj = edges[source][i];

        if(!visit[adj]){
            child++;
            parent[adj] = source;
            dfs(adj);

            low[source] = min(low[source],low[adj]);

            if(parent[source] != -1 && low[adj] >= disc[source]){
                AP[source] = true; // at least one child of source has no back edge to ancestor of source
            }
            if(parent[source] == -1 && child > 1){
                AP[source] = true; // if the root has more than one "independent" children then it is an AP
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
    int T,kase = 0; scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d %d",&n,&m);
        init(n);

        for(int i = 0 ; i < m ; i++){
            int a,b; scanf("%d %d",&a,&b);
            edges[a].pb(b);
            edges[b].pb(a);
        }

        dfs(1);

        int num = 0;

        for(int i = 1 ; i <= n ; i++){
            if(AP[i]) num++;
        }

        printf("Case %d: %d\n",++kase,num);
    }
    return 0;
}

