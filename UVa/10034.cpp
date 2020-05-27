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

struct node{
    int index; // representing node by a point
    double cost;

    node(){}

    node(int u,double c){
        index = u;
        cost = c;
    }

    bool operator < (const node &obj) const{
        return cost > obj.cost;
    }
};

const int MAXN = 105;
vector < node > edges[MAXN];
bool visit[MAXN];
int n;

double prim(int source){
    priority_queue < node > pq;
    pq.push(node(source,0.0));
    double mincost = 0.0;

    memset(visit,0,sizeof(visit));

    while(!pq.empty()){
        node top = pq.top();
        pq.pop();

        if(visit[top.index]) continue;
        mincost += top.cost;
        visit[top.index] = true;

        for(int i = 0 ; i < edges[top.index].size() ; i++){
            node to = edges[top.index][i];
            if(!visit[to.index]) pq.push(node(to.index,to.cost));
        }
    }

    return mincost;
}

inline void clr(){
    for(int i = 1 ; i <= n ; i++)
        edges[i].clear();
}

inline double dist(double a,double b,double c,double d){
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int main(){
    //infile; outfile;
    bool newLine = false;
    int T; scanf("%d",&T);
    while(T--){
        if(newLine) printf("\n");
        newLine = true;
        clr();
        scanf("%d",&n);
        map < int , pair < double, double > > mmp;
        int kk = 1;
        for(int i = 1 ; i <= n ; i++){
            double a,b;
            scanf("%lf %lf",&a,&b);
            if(mmp.find(kk) == mmp.end()){
                mmp[kk++] = mp(a,b);
            }
        }

        for(int i = 1 ; i <= n ; i++){
            for(int j = i + 1 ; j <= n ; j++){
                double dst = dist(mmp[i].first,mmp[i].second,mmp[j].first,mmp[j].second);
                edges[i].pb(node(j,dst));
                edges[j].pb(node(i,dst));
            }
        }

        double cc = prim(1);
        printf("%0.2f\n",cc);
    }
    return 0;
}


