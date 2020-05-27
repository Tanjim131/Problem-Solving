#include <iostream>
#include <cstdio>
#include <unordered_set>

using namespace std;

const int MAXN = 10005;
int par[MAXN] , Rank[MAXN], cc[MAXN];
int n;

void init(){
    for(int i = 0 ; i < n ; i++){
        par[i] = i;
        Rank[i] = 0;
        int p; scanf("%d",&p);
        cc[i] = p;
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

    if(p == q) return;

    if(Rank[p] < Rank[q]){
        par[p] = q;
        cc[q] += cc[p];
    }
    else{
        par[q] = p;
        cc[p] += cc[q];
    }
    if(Rank[p] == Rank[q]) Rank[p]++;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int m;
        scanf("%d %d",&n,&m);
        init();
        for(int i = 0 ; i < m ; i++){
            int x,y; scanf("%d %d",&x,&y);
            Union(x,y);
        }
        unordered_set < int > us;
        for(int i = 0 ; i < n ; i++){
            us.insert(root(i));
        }
        bool f = true;
        auto it = us.begin();
        while(it != us.end()){
            if(cc[*it] != 0){
                f = false;
                break;
            }
            it++;
        }
        if(f) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
