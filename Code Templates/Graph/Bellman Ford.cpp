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
#define PII pair < int , int >
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

class node{
    public:
        int index;
        int cost;

        node(int u,int c){
            index = u;
            cost = c;
        }
};

const int MAXN = 1000 + 5;
const int INF = 1e8;

int distance[MAXN],parent[MAXN];
vector < node > edge[MAXN];
int v; // number of vertices

void init(){
    for(int i = 0 ; i < v ; i++){
        distance[i] = INF;
        parent[i] = -1;
        edge[i].clear();
    }
}

bool BellmanFord(int source){
    distance[source] = 0;

    for(int k = 1 ; k <= v - 1 ; k++){
        for(int i = 0 ; i < v ; i++){
            for(int j = 0 ; j < edge[i].size() ; j++){
                node qq = edge[i][j];
                if(distance[i] + qq.cost < distance[qq.index]){
                    distance[qq.index] = distance[i] + qq.cost;
                    parent[qq.index] = i;
                }
            }
        }
    }

    for(int i = 0 ; i < v ; i++){
        for(int j = 0 ; j < edge[i].size() ; j++){
            node qq = edge[i][j];
            if(distance[i] + qq.cost < distance[qq.index]){
                return true; // negative cycle exists
            }
        }
    }
    return false; // no negative cycle
}
