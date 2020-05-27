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

const int MAXN = 1000 + 5;
vector < int > graph[MAXN];
vector < int > alone;
int people[100 + 5];
bool visit[MAXN][MAXN];
int numberOfCities;

int bfs(int source){
    queue < int > q;
    q.push(source);
    int original = source;
    visit[source][source] = true;

    while(!q.empty()){
        source = q.front();
        q.pop();

        for(int i = 0 ; i < graph[source].size() ; i++){
            int adj = graph[source][i];

            if(!visit[original][adj]){
                visit[original][adj] = true;
                q.push(adj);
            }
        }
    }

    int counter = 0;

    //printf("Source: %d\n",source);

    for(int i = 1 ; i <= numberOfCities ; i++){
        if(visit[original][i]) {
            //printf("visiting %d\n",i);
            counter++;
        }
    }

    if(counter == 1) alone.pb(source);

    return counter;
}

inline void clr(){
    alone.clear();
    memset(visit,0,sizeof(visit));
    for(int i = 0 ; i < MAXN ; i++){
        graph[i].clear();
    }
}

void printGraph(){
    for(int i = 1 ; i <= numberOfCities ; i++){
        printf("%d: ",i);
        for(int j = 0 ; j < graph[i].size() ; j++){
            printf("(%d) ",graph[i][j]);
        }
        printf("\n");
    }
}

int main(){
    //infile("in.txt");
    //outfile("out.txt");
    int T,kase = 0;
    scanf("%d",&T);
    while(T--){
        clr();
        int k,m;
        scanf("%d %d %d",&k,&numberOfCities,&m);
        for(int i = 0 ; i < k ; i++) scanf("%d",&people[i]);
        for(int i = 0 ; i < m ; i++){
            int from,to;
            scanf("%d %d",&from,&to);
            graph[from].pb(to);
        }

        //printGraph();

        int mx = MAXN;
        for(int i = 0 ; i < k ; i++){
            int ans = bfs(people[i]);
            mx = min(mx,ans);
        }

        for(int i = 0 ; i < alone.size() ; i++){
            int vertex = alone[i];
            for(int j = 0 ; j < k ; j++){
                if(vertex != people[j] && !visit[people[j]][vertex]){
                    mx = 0;
                    break;
                }
            }
            if(!mx) break;
        }

        printf("Case %d: %d\n",++kase,mx);
    }
    return 0;
}


