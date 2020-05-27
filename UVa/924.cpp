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

const int MAXN = 2500 + 5;
vector < int > v[MAXN];
int vis[MAXN],dis[MAXN];

inline void BFS(int source,int nodes){
    memset(vis,false,sizeof(vis));
    memset(dis,0,sizeof(dis));
    queue < int > q;
    dis[source] = 0;
    vis[source] = true;
    q.push(source);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0 ; i < v[u].size() ; i++){
            int s = v[u][i];
            if(!vis[s]){
                vis[s] = true;
                dis[s] = dis[u] + 1;
                q.push(s);
            }
        }
    }

    bool flag = false;
    set < int > s;
    multiset < int > ms;

    for(int i = 0 ; i < nodes ; i++){
        if(i != source && vis[i]){
            flag = true;
            s.insert(dis[i]);
            ms.insert(dis[i]);
        }
    }

    if(!flag){
        printf("0\n");
        return;
    }

    int mxSize = -1;
    int day = -1;

    auto it = s.begin();
    while(it != s.end()){
        int counter = ms.count(*it);
        if(mxSize < counter){
            mxSize = counter;
            day = *it;
        }
        it++;
    }

    printf("%d %d\n",mxSize,day);
}

int main(){
    int E,N,X,T,source;
    scanf("%d",&E);
    for(int i = 0 ; i < E ; i++){
        scanf("%d",&N);
        for(int j = 0 ; j < N ; j++){
            scanf("%d",&X);
            v[i].pb(X);
        }
    }

    scanf("%d",&T);
    while(T--){
        scanf("%d",&source);
        BFS(source,E);
    }

    return 0;
}
