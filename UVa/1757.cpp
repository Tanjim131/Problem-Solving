#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 30;

vector < int > edges[MAXN];
int vis[30];

void dfs(int source){
    vis[source] = 1;
    for(int i = 0 ; i < edges[source].size() ; i++){
        if(vis[edges[source][i]] == 0){
            dfs(edges[source][i]);
        }
    }
}

bool ret(string a,string b){
    if(a.size() != b.size()) return false;
    for(int i = 0 ; i < a.size() ; i++){
        if(a[i] == b[i]) continue;
        else{
            memset(vis,0,sizeof(vis));
            dfs(a[i] - 'a');
            if(!vis[b[i] - 'a']) return false;
        }
    }
    return true;
}

int main(){
    int m,n;
    while(scanf("%d %d",&m,&n) != EOF){
        char a,b;
        for(int i = 0 ; i < MAXN ; i++) edges[i].clear();
        for(int i = 0 ; i < m ; i++){
            scanf(" %c %c",&a,&b);
            edges[a - 'a'].push_back(b - 'a');
        }
        string p,q;
        for(int i = 0 ; i < n ; i++){
            cin >> p >> q;
            if(ret(p,q)) printf("yes\n");
            else printf("no\n");
        }
    }
    return 0;
}
