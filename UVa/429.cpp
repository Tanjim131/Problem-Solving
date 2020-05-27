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

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

const int MAXN = 200 + 5;
vector < int > edges[MAXN];
bool visit[MAXN];
int dist[MAXN];

void init(){
    for(int i = 0 ; i < MAXN ; i++){
        edges[i].clear();
    }
}

inline bool check(string a,string b){
    if(a == b) return false;
    int counter = 0;
    for(int i = 0 ; i < a.size() ; i++){
        if(a[i] != b[i]){
            counter++;
            if(counter > 1) return false;
        }
    }
    return true;
}

void buildGraph(vector < string > &v, map < string , int > &m){
    for(int i = 0 ; i < v.size() ; i++){
        for(int j = i + 1 ; j < v.size() ; j++){
            if(check(v[i],v[j])){
                int x = m[v[i]];
                int y = m[v[j]];
                //cout << "x " << x << " y " << y << endl;
                edges[x].pb(y);
                edges[y].pb(x);
            }
        }
    }
}

int bfs(int source,int destination){
    memset(visit,false,sizeof(visit));
    memset(dist,0,sizeof(dist));
    queue < int > q;
    q.push(source);
    visit[source] = true;

    while(!q.empty()){
        source = q.front();
        q.pop();

        for(int i = 0 ; i < edges[source].size() ; i++){
            int adj = edges[source][i];
            if(!visit[adj]){
                visit[adj] = true;
                //printf("Going from %d to %d\n",source,adj);
                dist[adj] = dist[source] + 1;
                if(adj == destination) return dist[destination];
                q.push(adj);
            }
        }
    }
}

/*void printGraph(int nodes){
    for(int i = 1 ; i <= nodes ; i++){
        printf("%d: ",i);
        for(int j = 0 ; j < edges[i].size() ; j++){
            printf("%d ",edges[i][j]);
        }
        printf("\n");
    }
}*/

int main(){
    //infile("in.txt");
    //outfile("out.txt");
    int T;
    scanf("%d",&T);
    string in;
    while(T--){
        init();
        int a = 1;
        map < string , int > m;
        vector < string > words;
        while(getline(cin,in)){
            if(in == "") continue;
            if(in == "*") break;
            if(m.find(in) == m.end()) {
                m[in] = a++;
                //printf("Mapping %s with %d\n",in.c_str(),a - 1);
            }
            words.pb(in);
        }
        // input taken
        buildGraph(words,m);
        //printGraph(a - 1);
        string s,t;
        while(getline(cin,in) && in != ""){
            stringstream ss(in);
            ss >> s >> t;
            int source = m[s];
            int destination = m[t];
            //cout << "source " << source << " destination " << destination << endl;
            int ans = bfs(source,destination);
            if(s == t) printf("%s %s 0\n",s.c_str(),t.c_str());
            else printf("%s %s %d\n",s.c_str(),t.c_str(),ans);
        }
        if(T) printf("\n");
    }
    return 0;
}
