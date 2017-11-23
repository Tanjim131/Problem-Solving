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

vector < int > in[MAXN];
vector < int > out[MAXN];
int visit[MAXN];
int cost[MAXN][MAXN];

void init(){
    for(int i = 0 ; i < MAXN ; i++){
        in[i].clear();
        out[i].clear();
    }
}

inline void addEdge(int from,int to,int c){
    out[from].pb(to);
    in[to].pb(from);
    cost[from][to] = c;
}

int traverse(int source){
    // three possibilities
    // source can have 2 incoming edges, 2 outgoing edges or 1 incoming and 1 outgoing
    memset(visit,0,sizeof(visit));
    visit[source] = true;
    int cc = 0,rev = 0;

    while(true){
        if(out[source].size() == 2){
            // two outgoing edges, choose any one
            int a = out[source][0];
            int b = out[source][1];

            if(!visit[a]){
                visit[a] = true;
                rev += cost[source][a];
                source = a;
            }
            else if(!visit[b]){
                visit[b] = true;
                rev += cost[source][b];
                source = b;
            }
            else{
                //both outgoing edges are visited, so we have reached the end of our traversal
                rev += cost[source][1];
                source = 1;
            }
        }
        else if(out[source].size() == 1){
            // one outgoing edge
            int a = out[source][0];
            int b = in[source][0];

            if(!visit[a]){
                visit[a] = true;
                rev += cost[source][a];
                source = a;
            }
            else if(!visit[b]){
                visit[b] = true;
                cc += cost[b][source];
                source = b;
            }
            else{
                // end of traversal
                // if the outgoing edge points to source then increment reverse cost
                // if the incoming edge points from source then increment forward cost
                if(a == 1) rev += cost[source][1];
                else if(b == 1) cc += cost[1][source];
                source = 1;
            }
        }
        else{
            // no outgoing edges , 2 incoming edges
            int a = in[source][0];
            int b = in[source][1];

            if(!visit[a]){
                visit[a] = true;
                cc += cost[a][source];
                source = a;
            }
            else if(!visit[b]){
                visit[b] = true;
                cc += cost[b][source];
                source = b;
            }
            else{
                // both edges are visited, so increment the forward cost, edge pointing from the source(1)
                cc += cost[1][source];
                source = 1;
            }
        }

        if(source == 1) break;
    }

    return min(cc,rev);
}


int main(){
    //infile("in.txt");
    //outfile("out.txt");
    int T,kase = 0;
    scanf("%d",&T);
    while(T--){
        init();
        int N;
        scanf("%d",&N);
        for(int i = 0 ; i < N ; i++){
            int from,to,weight;
            scanf("%d %d %d",&from,&to,&weight);
            addEdge(from,to,weight);
        }
        printf("Case %d: %d\n",++kase,traverse(1));
    }
    return 0;
}


