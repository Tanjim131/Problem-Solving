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

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

const int MAXN = 30;
vector < int > edges[MAXN];
int vis[MAXN];
int in[MAXN];
int nodes;
vector < int > res;
vector < char > vv;
unordered_map < char , int > ump;
int ret;

void topsort(vector < vector < char > > &qq){
    //bool flag = false;

    for(int i = 0 ; i < nodes ; i++){
        if(in[i] == 0 && !vis[i]){
            for(int j = 0 ; j < edges[i].size() ; j++) in[edges[i][j]]--;
            res.pb(i);
            vis[i] = true;
            topsort(qq);
            // now backtrack
            vis[i] = false;
            res.erase(res.end() - 1);
            for(int j = 0 ; j < edges[i].size() ; j++) in[edges[i][j]]++;
            //flag = true;
        }
    }

    if(res.size() == nodes){
        vector < char > vc;
        for(int i = 0 ; i < res.size() ; i++){
            vc.pb(vv[res[i]]);
        }
        qq.pb(vc);
    }
}

void reset(){
    memset(vis,0,sizeof(vis));
    memset(in,0,sizeof(in));
    for(int i = 0 ; i < MAXN ; i++) edges[i].clear();
    vv.clear();
    ump.clear();
    ret = 0;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string input;
    bool f = false;
    reset();
    while(getline(cin,input)){
        if(f) printf("\n");
        f = true;
        char c;
        stringstream ss(input);
        nodes = 0;
        while(ss >> c){
            if(ump.find(c) == ump.end()) {
                ump[c] = ret++;
                vv.pb(c);
            }
        }
        nodes = ret;
        getline(cin,input);
        stringstream rr(input);
        char a,b;
        while(rr >> a >> b){
            edges[ump[a]].pb(ump[b]);
            in[ump[b]]++;
        }
        vector < vector < char > > qq;
        topsort(qq);
        sort(qq.begin(),qq.end());
        for(int i = 0 ; i < qq.size() ; i++){
            for(int j = 0 ; j < qq[i].size() ; j++){
                printf("%c",qq[i][j]);
            }
            printf("\n");
        }
        reset();
    }
    return 0;
}
