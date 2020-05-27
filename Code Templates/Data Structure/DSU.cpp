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
#define infile(f) freopen(f,"r",stdin)
#define outfile(f) freopen(f,"w",stdout)

inline bool checkBit(int mask,int pos) { return (bool) (mask & (1 << pos)); }
inline int setBit(int mask,int pos) { return (mask | (1 << pos)); }
//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

const int MAXN = 30000 + 5; // adjust max size accordingly
int par[MAXN],Rank[MAXN];

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

int main(){


    return 0;
}


