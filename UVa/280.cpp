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
#define pii pair < int , int >
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

vector < int > edges[105];
bool vis[105]; bool reach[105];
int n,t;

void dfs(int source){
    if(t) vis[source] = 1;
    t++;
    for(int i = 0 ; i < edges[source].size() ; i++){
        if(!vis[edges[source][i]]) dfs(edges[source][i]);
    }
}

int main(){
    //infile; outfile;
    while(scanf("%d",&n) != EOF){
        if(!n) break;
        for(int i = 0 ; i < 105 ; i++) edges[i].clear();
        memset(reach,0,sizeof(reach));
        string input;
        getchar();
        while(getline(cin,input)){
            if(input == "0") break;
            stringstream ss(input);
            int sv; ss >> sv;
            int ev;
            while(ss >> ev){
                if(!ev) break;
                if(sv == ev) reach[sv] = true;
                edges[sv].pb(ev);
            }
        }
        int qq;
        scanf("%d",&qq);
        for(int i = 0 ; i < qq ; i++){
            int x; scanf("%d",&x);
            memset(vis,0,sizeof(vis));
            t = 0;
            dfs(x);
            vector < int > ans;
            for(int j = 1 ; j <= n ; j++){
                if(!vis[j]){
                    if(j == x && reach[j])  continue;
                    ans.pb(j);
                }
            }
            printf("%d",ans.size());
            if(ans.size()){
                for(int i = 0 ; i < ans.size() ; i++){
                    printf(" %d",ans[i]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
