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

const int MAXN = 1000 + 5;

class node
{
public:
    int index;
    int cost;

    node() {}

    node(int u,int c)
    {
        index = u;
        cost = c;
    }
};

int visit[MAXN];
int disc[MAXN],low[MAXN]; // discovery time and low time
bool stackMember[MAXN]; // to check whether a node is still on the stack
vector < node > edge[MAXN]; // original graph
stack < int > s; // stack for DFS traversal
int v; // number of vertices

void init()
{
    for(int i = 0 ; i < v ; i++)
    {
        edge[i].clear();
    }
    memset(visit,0,sizeof(visit));
    memset(disc,0,sizeof(disc));
    memset(low,0,sizeof(low));
    memset(stackMember,0,sizeof(stackMember));
}

void dfsUtil(int source)
{
    static int ti = 0;
    disc[source] = low[source] = (++ti);
    visit[source] = true;
    s.push(source);
    stackMember[source] = true;

    for(int i = 0 ; i < edge[source].size() ; i++)
    {
        int adj = edge[source][i].index;

        if(!visit[adj])
        {
            dfsUtil(adj);
            low[source] = min(low[source],low[adj]);
        }
        else if(stackMember[adj])
        {
            low[source] = min(low[source],disc[adj]);
        }
    }


    vector < int > sccv;

    int w = 0;

    if(disc[source] == low[source])
    {
        while(s.top() != source)
        {
            w = (int) s.top();
            sccv.pb(w);
            stackMember[w] = false;
            s.pop();
        }
        w = (int) s.top();
        sccv.pb(w);
        stackMember[w] = false;
        s.pop();
    }
}

void TarjanSCC()
{
    for(int i = 0 ; i < v ; i++)
    {
        if(!visit[i]) dfsUtil(i);
    }
}
