#include <iostream>
#include <cstdio>
#include <unordered_set>

using namespace std;

const int MAXN = 50005;
int par[MAXN] , Rank[MAXN];
int n,ans;

void init(){
    for(int i = 0 ; i < n ; i++){
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
    //if(p == q) return; // if two people are of same religion we do not need to decrement unique religions by one
    //ans--;
    if(Rank[p] < Rank[q]) par[p] = q;
    else par[q] = p;
    if(Rank[p] == Rank[q]) Rank[p]++;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int m,k = 0;
    while(scanf("%d %d",&n,&m) != EOF){
        if(!n && !m) break;
        init();
        ans = n;
        for(int i = 0 ; i < m ; i++){
            int x,y; scanf("%d %d",&x,&y);
            Union(x,y);
        }
        unordered_set < int > us;
        for(int i = 1 ; i <= n ; i++){
            us.insert(root(i));
        }
        printf("Case %d: %d\n",++k,us.size());
        //printf("Case %d: %d\n",++k,ans);
    }
    return 0;
}
