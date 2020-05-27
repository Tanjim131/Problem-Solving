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
    int index;
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

int prim(int source){
    priority_queue < node > pq;
    pq.push(node(source,0.0));
    double mincost = 0.0;

    memset(visit,0,sizeof(visit));

    while(!pq.empty()){
        node top = pq.top();
        pq.pop();

        if(visit[top.index]) continue;
        mincost = max(mincost,top.cost);
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


int main(){


    return 0;
}


