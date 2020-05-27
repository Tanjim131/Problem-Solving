#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>

using namespace std;

#define LL long long
#define pb push_back
#define mp make_pair
#define PII pair < int , int >
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)

inline bool checkBit(int mask,int pos) { return (bool) (mask & (1 << pos)); }
inline int setBit(int mask,int pos) { return (mask | (1 << pos)); }
//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

class node{
    public:
        int x;
        int y;

        node(){}

        node(int x,int y){
            this -> x = x;
            this -> y = y;
        }

        bool operator < (const node &ob) const{
            if(x == ob.x) return y < ob.y;
            return x < ob.x;
        }
};

class edge{
    public:
        node from;
        node to;
        double weight;

        edge(){}

        edge(node from,node to,double weight){
            this -> from = from;
            this -> to = to;
            this -> weight = weight;
        }

        bool operator < (const edge &ob) const{
            return weight < ob.weight;
        }

};



const int MAXN = 1000 + 5; // adjust max size accordingly
int par[MAXN],Rank[MAXN];

vector < edge > edges;
vector < double > MST;
vector < node > nodes;
map < node , int > m;

void initialize(int n){
    for(int i = 0 ; i < n ; i++){
        par[i] = i; // initially everybody is their own parent
        Rank[i] = 1; // subset size 1
    }
}

int Find(int i){
    while(par[i] != i){
        par[i] = par[par[i]]; // setting's i's grandparent as i's new parent, flattening the tree, path compression
        i = par[i]; // walking up the ladder;
    }
    return i;
}

void Union(int a,int b){
    int rootA = Find(a);
    int rootB = Find(b);

    if(rootA == rootB) return; // if they are connected already, no need to go further

    if(Rank[rootA] < Rank[rootB]){ // balancing the tree
        par[rootA] = rootB;
        Rank[rootB] += Rank[rootA];
    } else{
        par[rootB] = rootA;
        Rank[rootA] += Rank[rootB];
    }
}

void Kruskal(int nodes){
    initialize(nodes);
    sort(edges.begin(),edges.end());
    for(int i = 0 ; i < edges.size() ; i++){
        node from = edges[i].from;
        node to = edges[i].to;
        double weight = edges[i].weight;

        if(Find(m[from]) != Find(m[to])){
            MST.pb(weight);
            Union(m[from],m[to]);
        }
    }
}

inline double calculateDist(node a,node b){
    double xx = (a.x - b.x) * (a.x - b.x);
    double yy = (a.y - b.y) * (a.y - b.y);

    return sqrt(xx + yy);
}

void allClear(){
    nodes.clear();
    edges.clear();
    MST.clear();
    m.clear();
}

int main(){
    //infile;
    //outfile;
    int T,k = 0;
    scanf("%d",&T);
    while(T--){
        allClear();
        int cities,threshold;
        scanf("%d %d",&cities,&threshold);

        int aa = 0;

        for(int i = 0 ; i < cities ; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            nodes.pb(node(x,y));
            if(m.find(node(x,y)) == m.end()){
                m.insert(mp(node(x,y),aa++));
            }
        }

        //for(int i = 0 ; i < nodes.size() ; i++){
        //    cout << nodes[i].x << " " << nodes[i].y << endl;
        //}

        for(int i = 0 ; i < nodes.size() ; i++){
            for(int j = i + 1 ; j < nodes.size() ; j++){
                double dist = calculateDist(nodes[i],nodes[j]);
                edges.pb(edge(nodes[i],nodes[j],dist));
            }
        }

        Kruskal(cities);

        int states = 1;
        double roads = 0.0;
        double railway = 0.0;

        for(int i = 0 ; i < MST.size() ; i++){
            if(MST[i] <= threshold) roads += MST[i];
            else {
                railway += MST[i];
                states++;
            }
        }

        printf("Case #%d: %d %d %d\n",++k,states,(int)round(roads),(int)round(railway));
    }

    return 0;
}



