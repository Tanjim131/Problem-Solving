#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 6;

vector<int> edges[MAXN];
bool visit[MAXN];
int color[MAXN];
queue<int>q;

bool bfs(int s){
    memset(visit, 0, sizeof(visit));
    memset(color, 0, sizeof(visit));
    visit[s] = 1;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0 ; i < edges[u].size() ; i++){
            int v = edges[u][i];
            if(visit[v] == 0){
                visit[v] = 1;
                color[v] = color[u] ^ 1;
                q.push(v);
            }
            else{
                if(color[u] == color[v]) return false;
                else continue;
            }
        }
    }
    return true;
}
int main(){
    int n,l;
    while(cin >> n >> l){
        if(!n) break;
        for(int i = 0 ; i < n ; i++) edges[i].clear();
        while(!q.empty()) q.pop();
        for(int i = 0 ; i < l ; i++){
            int x,y;
            cin >> x >> y;
            edges[x].emplace_back(y);
            edges[y].emplace_back(x);
        }
        bool ret = bfs(0);
        if(ret) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
    }
    return 0;
}
