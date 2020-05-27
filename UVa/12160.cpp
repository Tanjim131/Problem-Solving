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

const int MAXN = 10000 + 5;
//vector < int > v[MAXN];
int vis[MAXN],dist[MAXN],option[10];

int BFS(int source,int destination,int num){
    memset(vis,0,sizeof(vis));
    memset(dist,0,sizeof(dist));
    queue < int > q;
    q.push(source);
    vis[source] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0 ; i < num ; i++){
            int sum = (u + option[i]) % 10000; // last 4 significant digit
            //cout << "sum " << sum << endl;
            if(!vis[sum]){
                vis[sum] = 1;
                dist[sum] = dist[u] + 1;
                q.push(sum);
            }
        }
    }

    if(!dist[destination]){
        if(source == destination) return 0;
        return -1;
    } else return dist[destination];
}

int main(){
    int L,U,R,k = 0;
    while(scanf("%d %d %d",&L,&U,&R) != EOF){
        if(!L && !U && !R) break;
        for(int i = 0 ; i < R ; i++){
            scanf("%d",&option[i]);
        }
        int answer = BFS(L,U,R);
        if(answer == -1) printf("Case %d: Permanently Locked\n",++k);
        else printf("Case %d: %d\n",++k,answer);
    }

    return 0;
}
