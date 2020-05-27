#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define pb push_back

const int MAXN = 30005;
int par[MAXN] , Rank[MAXN];
int n;

void init(){
    for(int i = 0 ; i < MAXN ; i++){
        par[i] = i;
        Rank[i] = 0;
    }
}

int root(int i){
    if(par[i] == i) return i;
    par[i] = root(par[i]); // path compression
    return par[i];
}

void Union(int a,int b){
    int p = root(a);
    int q = root(b);

    if(p == q) return; // a and b are already connected

    if(Rank[p] < Rank[q]) par[p] = q;
    else par[q] = p;
    if(Rank[p] == Rank[q]) Rank[p]++;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int m;
    while(scanf("%d %d",&n,&m) != EOF){
        if(!n && !m) break;
        init();
        for(int i = 0 ; i < m ; i++){
            int k; scanf("%d",&k);
            vector < int > vv;
            for(int j = 0 ; j < k ; j++){
                int x; scanf("%d",&x);
                vv.pb(x);
            }
            for(int j = 0 ; j < vv.size() - 1 ; j++){
                Union(vv[j],vv[j + 1]);
            }
        }

        int suspect = 1;
        int qq = root(0);

        for(int i = 1 ; i < n ; i++){
            int ret = root(i);
            if(qq == ret) suspect++;
        }

        printf("%d\n",suspect);
    }
    return 0;
}
