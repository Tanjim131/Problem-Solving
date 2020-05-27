#include <iostream>
#include <cstdio>
#include <unordered_map>

using namespace std;

const int MAXN = 100005;
int par[MAXN] , Rank[MAXN];

void init(){
    for(int i = 1 ; i <= MAXN ; i++){
        par[i] = i;
        Rank[i] = 1;
    }
}

int root(int i){
    if(par[i] == i) return i;
    par[i] = root(par[i]); // path compression
    return par[i];
}

int Union(int a,int b){
    int p = root(a);
    int q = root(b);
    if(p != q){
        if(Rank[p] < Rank[q]){
            Rank[q] += Rank[p];
            par[p] = q;
            return Rank[q];
        }
        Rank[p] += Rank[q];
        par[q] = p;
        return Rank[p];
    }
    return Rank[p];
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        init();
        unordered_map < string , int > ump;
        string a,b;
        int k = 1;
        for(int i = 0 ; i < n ; i++){
            cin >> a >> b;
            if(ump.find(a) == ump.end()) ump[a] = k++;
            if(ump.find(b) == ump.end()) ump[b] = k++;
            int x = ump[a];
            int y = ump[b];
            int pp = root(x);
            int qq = root(y);
            printf("%d\n",Union(x,y));
        }
    }
    return 0;
}
