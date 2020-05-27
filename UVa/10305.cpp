#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;

struct ret{
    int node;
    int start;
    int finish;
}arr[MAXN];

vector < int > edges[MAXN];
bool vis[MAXN];
int n,m,t;

void dfs(int source){
    vis[source] = 1;
    arr[source].node = source;
    arr[source].start = t++;
    for(int i = 0 ; i < edges[source].size() ; i++){
        if(!vis[edges[source][i]]){
            dfs(edges[source][i]);
        }
    }
    arr[source].finish = t++;
}

void dag(){
    memset(vis,0,sizeof(vis));
    memset(arr,0,sizeof(arr));
    t = 0;
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]) dfs(i);
    }
}

bool cmp(ret a, ret b){
    return a.finish > b.finish;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d %d",&n,&m) != EOF){
        if(n == 0 && m == 0) break;
        for(int i = 0 ; i < MAXN ; i++) edges[i].clear();
        for(int i = 0 ; i < m ; i++){
            int p , q ;
            scanf("%d %d",&p,&q);
            edges[p].push_back(q);
        }
        dag();
        sort(arr + 1,arr + n + 1,cmp);
        for(int i = 1 ; i <= n ; i++){
            printf("%d",arr[i].node);
            if(i != n) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
