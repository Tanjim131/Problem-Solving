#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>

using namespace std;

const int MAXN = 100005;
int par[MAXN];
int Rank[MAXN];
int n;

void init(){
    for(int i = 1 ; i <= n ; i++){
        par[i] = i;
        Rank[i] = 0;
    }
}

int root(int i){
    if(par[i] == i) return i;
    par[i] = root(par[i]); // path compression
    return par[i];
}

void Union(int a , int b){
    int root_a = root(a);
    int root_b = root(b);
    if(Rank[root_a] < Rank[root_b]) par[root_a] = root_b;
    else par[root_b] = root_a;
    if(Rank[root_a] == Rank[root_b]) Rank[root_a]++;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        init();
        int su = 0 , usu = 0;
        string in;
        getchar();
        while(getline(cin,in)){
            if(in.size() == 0) break;
            char a; int p,q;
            stringstream ss(in);
            ss >> a >> p >> q;
            if(a == 'c') Union(p,q);
            else{
                if(root(p) == root(q)) su++;
                else usu++;
            }
        }
        printf("%d,%d\n",su,usu);
        if(T) printf("\n");
    }
    return 0;
}
