#include <cstdio>
#include <unordered_set>

using namespace std;

const int MAXN = 30005;
int par[MAXN] , Rank[MAXN];
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

void Union(int a,int b){
    //cout << "a " << a << " b " << b << endl;
    int p = root(a);
    int q = root(b);
    //cout << "p " << p << " q " << q << endl;
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
        int m;
        scanf("%d %d",&n,&m);
        init();

        for(int i = 0 ; i < m ; i++){
            int x,y; scanf("%d %d",&x,&y);
            Union(x,y); // building friendship
        }

        unordered_set < int > us;
        unordered_multiset < int > ums;

        for(int i = 1 ; i <= n ; i++){
            int qq = root(i);
            us.insert(qq);
            ums.insert(qq);
        }

        int ret = -1;
        auto it = us.begin();

        while(it != us.end()){
            int counter = ums.count(*it);
            ret = (ret < counter) ? counter : ret;
            it++;
        }

        printf("%d\n",ret);
    }
    return 0;
}
