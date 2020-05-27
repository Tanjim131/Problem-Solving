#include <cstdio>
#include <iostream>
#include <unordered_map>

using namespace std;

const int MAXN = 5005;
int par[MAXN] , Rank[MAXN];
int n;

void init(){
    for(int i = 1 ; i <= n ; i++){
        par[i] = i;
        Rank[i] = 1;
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
    if(p != q){
        if(Rank[p] < Rank[q]){
            Rank[q] += Rank[p];
            par[p] = q;
        }
        else{
            Rank[p] += Rank[q];
            par[q] = p;
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int r;
    while(scanf("%d %d",&n,&r) != EOF){
        if(n == 0 && r == 0) break;
        init();
        unordered_map < string , int > ump;
        int k = 1;

        for(int i = 1 ; i <= n ; i++){
            string a; cin >> a;
            if(ump.find(a) == ump.end()) ump[a] = k++;
        }

        string a , b;
        for(int i = 0 ; i < r ; i++){
            cin >> a >> b;
            Union(ump[a],ump[b]);
        }

        int mx = -1;
        for(int i = 1 ; i <= n ; i++){
            mx = (mx < Rank[i]) ? Rank[i] : mx;
        }
        printf("%d\n",mx);
    }

    return 0;
}

