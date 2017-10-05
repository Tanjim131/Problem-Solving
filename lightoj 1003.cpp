#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

#define pb push_back

const int MAXN = 5005;
vector < int > edges[MAXN];
int in[MAXN],out[MAXN];

bool check(int nodes){
    while(1){
        bool flag = false;
        int ret = 0;
        for(int i = 0 ; i < nodes ; i++){
            if(in[i] == 0){
                flag = true;
                ret = i;
                break;
            }
        }
        if(!flag) break;
        in[ret] = -1;
        for(int i = 0 ; i < edges[ret].size() ; i++){
            in[edges[ret][i]]--;
            out[ret]--;
        }
    }
    for(int i = 0 ; i < nodes ; i++){
        if(in[i] == -1 && out[i] == 0) continue;
        else return false;
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
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        int n;
        scanf("%d",&n);
        map < string , int > ump;
        int num = 0;
        string a,b;
        int ret = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> a >> b;
            if(ump.find(a) == ump.end()){
                ump[a] = ret++;
            }
            if(ump.find(b) == ump.end()){
                ump[b] = ret++;
            }
            out[ump[a]]++;
            in[ump[b]]++;
            edges[ump[a]].pb(ump[b]);
        }
        if(check(ret)) printf("Case %d: Yes\n",++k);
        else printf("Case %d: No\n",++k);
    }
    return 0;
}
