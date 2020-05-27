#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_set>

using namespace std;

const int MAXN = 30;
int par[MAXN] , Rank[MAXN];
int n;

void init(){
    for(int i = 0 ; i <= n ; i++){
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

    if(Rank[p] < Rank[q]) par[p] = q;
    else par[q] = p;
    if(Rank[p] == Rank[q]) Rank[p]++;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        char large;
        scanf(" %c",&large);
        n = large - 'A';
        init();
        string in;
        getchar();
        while(getline(cin,in)){
            if(in.size() == 0) break;
            Union(in[0] - 'A',in[1] - 'A');
        }
        unordered_set < int > us;
        // using unordered map to find out how many different roots are there
        for(int i = 0 ; i <= n ; i++){
            us.insert(root(i));
        }
        printf("%d\n",us.size());
        if(T) printf("\n");
    }
    return 0;
}
