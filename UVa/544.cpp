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

const int MAXN = 205;

struct node{
    int index;
    int cost;

    node(){}

    node(int u,int c){
        index = u;
        cost = c;
    }

    bool operator < (const node &obj) const{
        return cost < obj.cost;
    }
};

vector < node > edges[MAXN];
bool visit[MAXN];
int parent[MAXN];
int cost[MAXN];

void prim(int source){
    priority_queue < node > pq;
    memset(visit,0,sizeof(visit));
    memset(parent,-1,sizeof(parent));
    memset(cost,-1,sizeof(cost));

    pq.push(node(source,0));

    while(!pq.empty()){
        node top = pq.top();
        pq.pop();

        if(visit[top.index]) continue;

        visit[top.index] = true;

        for(int i = 0 ; i < edges[top.index].size() ; i++){
            node to = edges[top.index][i];

            if(!visit[to.index]){
                if(to.cost > cost[to.index]){
                    parent[to.index] = top.index;
                    cost[to.index] = to.cost;
                    pq.push(node(to.index,to.cost));
                }
            }
        }
    }
}

void clr(){
    for(int i = 0 ; i < MAXN ; i++){
        edges[i].clear();
    }
}

int main(){
    //infile; outfile;
    int n,r,kase = 0;
    while(scanf("%d %d",&n,&r) != EOF){
        if(!n && !r) break;
        clr();
        map <string,int> mp;
        string a,b;
        int c; int aa = 1;
        for(int i = 0 ; i < r ; i++){
            cin >> a >> b >> c;
            if(mp.find(a) == mp.end()){
                mp[a] = aa++;
                //cout << "mapping " << a << " with " << mp[a] << endl;
            }
            if(mp.find(b) == mp.end()){
                mp[b] = aa++;
                //cout << "mapping " << b << " with " << mp[b] << endl;
            }
            edges[mp[a]].pb(node(mp[b],c));
            edges[mp[b]].pb(node(mp[a],c));
        }

        cin >> a >> b;

        int idx = mp[a];
        prim(idx);

        int mincost = 10005;
        idx = mp[b];

        while(parent[idx] != -1){
            mincost = min(mincost,cost[idx]);
            //printf("%d %d\n",idx,parent[idx]);
            idx = parent[idx];
        }

        printf("Scenario #%d\n%d tons\n\n",++kase,mincost);
    }
    return 0;
}


