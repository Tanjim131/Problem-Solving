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
#define infile(f) freopen(f,"r",stdin)
#define outfile(f) freopen(f,"w",stdout)

inline bool checkBit(int mask,int pos) { return (bool) (mask & (1 << pos)); }
inline int setBit(int mask,int pos) { return (mask | (1 << pos)); }
//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

const int MAXN = 100000 + 5;
vector < int > v[MAXN];
int visit[MAXN],dist[MAXN];

int bfs(int source,int destination){
    memset(visit,0,sizeof(visit));
    memset(dist,0,sizeof(dist));
    queue < int > q;
    q.push(source);
    visit[source] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0 ; i < v[u].size() ; i++){
            int adj = v[u][i];
            if(!visit[adj]){
                visit[adj] = 1;
                dist[adj] = dist[u] + 1;
                if(adj == destination) break;
                q.push(adj);
            }
        }
    }

    return dist[destination];
}

void allClear(){
    for(int i = 0 ; i < MAXN ; i++){
        v[i].clear();
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        allClear();
        int n;
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++){
            int id,fellow; scanf("%d %d",&id,&fellow);
            for(int j = 0 ; j < fellow ; j++){
                int x; scanf("%d",&x);
                v[id].pb(x);
            }
        }

        int source,destination;
        scanf("%d %d",&source,&destination);
        int answer = bfs(source,destination);

        printf("%d %d %d\n",source,destination,answer - 1);
        if(T) printf("\n");
    }

    return 0;
}
