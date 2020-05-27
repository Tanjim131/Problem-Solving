#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair

const int MAXN = 1005;
const double eps = 1e-6;

vector < int > edges[MAXN];
int cost[MAXN];
bool vis[MAXN];
int n,m,counter,avg;
double cc;

void dfs(int source){
    vis[source] = 1;
    counter++;
    cc += cost[source];
    for(int i = 0 ; i < edges[source].size() ; i++){
        if(!vis[edges[source][i]]){
            dfs(edges[source][i]);
        }
    }
}

bool connected(){
    memset(vis,0,sizeof(vis));
    double tot = 0.0;
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            counter = 0 ;
            cc = 0.0;
            dfs(i);
            tot = cc / (1.0 * counter);
            //cout << "tot " << tot << " avg " << avg << endl;
            if(abs(tot - avg) < eps) continue;
            else return false;
        }
    }
    return true;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,k = 0;
    scanf("%d",&T);
    while(T--){
        for(int i = 0 ; i < MAXN ; i++) edges[i].clear();
        scanf("%d %d",&n,&m);
        int sum = 0;
        for(int i = 1 ; i <= n ; i++){
            scanf("%d",&cost[i]);
            sum += cost[i];
        }
        avg = (sum  * 1.0) / n;
        for(int i = 0 ; i < m ; i++){
            int u,v;
            scanf("%d %d",&u,&v);
            edges[u].pb(v);
            edges[v].pb(u);
        }
        if(connected()) printf("Case %d: Yes\n",++k);
        else printf("Case %d: No\n",++k);
    }
    return 0;
}
