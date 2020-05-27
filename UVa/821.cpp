#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair

const int MAXN = 100 + 5;
const int INF = 1e5;

class Edge{
public:
    int from;
    int to;

    Edge(){}

    Edge(int u,int v){
        from = u;
        to = v;
    }
};

class Graph{
    int vertex,edges;
    int matrix[MAXN][MAXN];
    int next[MAXN][MAXN];
    int predecessor[MAXN][MAXN];
public:
    Graph(){}

    Graph(int n,int m){
      vertex = n;
      edges = m;
      for(int i = 1 ; i <= vertex ; i++){
        for(int j = 1 ; j <= vertex ; j++){
          matrix[i][j] = (i == j) ? 0 : INF;
          next[i][j] = j; // initially there is no middle path
        }
      }
      memset(predecessor,-1,sizeof(predecessor));
    }

    void takeInput(){
      for(int i = 0 ; i < edges ; i++){
        int u,v,w; scanf("%d %d %d",&u,&v,&w);
        matrix[u][v] = w;
      }
    }

    void addEdge(int u,int v,int w){
        matrix[u][v] = w;
    }

    void printMatrix(){
      printf("\t");
      for(int i = 1 ; i <= vertex ; i++) printf("%d\t",i);
      printf("\n\n");

      for(int i = 1 ; i <= vertex ; i++){
        printf("%d\t",i);
        for(int j = 1 ; j <= vertex ; j++){
          if(matrix[i][j] == INF) printf("INF\t");
          else printf("%d\t",matrix[i][j]);
        }
        printf("\n");
      }
    }

    void FloydWarshall(){
      for(int i = 1 ; i <= vertex ; i++){
        for(int j = 1 ; j <= vertex ; j++){
          for(int k = 1 ; k <= vertex ; k++){
            if(matrix[j][k] > matrix[j][i] + matrix[i][k]){
              matrix[j][k] = matrix[j][i] + matrix[i][k];
              next[j][k] = next[j][i];
            }
          }
        }
      }
    }

    double answer(){
        int sum = 0;
        int counter = 0;
        for(int i = 1 ; i <= vertex ; i++){
            for(int j = 1 ; j <= vertex ; j++){
                if(matrix[i][j] == INF || matrix[i][j] == 0) continue;
                else sum += matrix[i][j] , counter++;
            }
        }
        return (sum *1.0)/counter;
    }

    /*void printNext(){
      printf("\t");
      for(int i = 1 ; i <= vertex ; i++) printf("%d\t",i);
      printf("\n\n");

      for(int i = 1 ; i <= vertex ; i++){
        printf("%d\t",i);
        for(int j = 1 ; j <= vertex ; j++){
          printf("%d\t",next[i][j]);
        }
        printf("\n");
      }
    }*/

    void path(int i,int j){ // path from i to j
        if(predecessor[i][j] != -1 || i == j) return;
        else if(matrix[i][j] == INF) {predecessor[i][j] = -1; return;}
        //cout << "i " << i << " j " << j << endl;
        int source = i,prev = -1;
        while(i != j){
            prev = i;
            i = next[i][j];
            //cout << "prev "  << prev << " i " << i << endl;
            if(predecessor[source][i] == -1) predecessor[source][i] = prev;
        }
    }

    void calculate(){
      for(int i = 1 ; i <= vertex ; i++){
        for(int j = 1 ; j <= vertex ; j++) path(i,j);
      }
    }

    void printPredecessor(){
      printf("\t");
      for(int i = 1 ; i <= vertex ; i++) printf("%d\t",i);
      printf("\n\n");

      for(int i = 1 ; i <= vertex ; i++){
        printf("%d\t",i);
        for(int j = 1 ; j <= vertex ; j++){
          if(predecessor[i][j] == -1) printf("INF\t");
          else printf("%d\t",predecessor[i][j]);
        }
        printf("\n");
      }
    }

    bool negCycle(){
        int i = 1,j = 1;
        while(i <= vertex && j <= vertex){
            if(matrix[i][j] < 0) return true;
            i++,j++;
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
    string str;
    int kases = 0;
    while(getline(cin,str)){
        int nodes = 0;
        stringstream ss(str);
        int u,v;
        ss >> u >> v;
        if(!u && !v) break;
        vector < Edge > vv;
        vv.pb(Edge(u,v));
        nodes = max(nodes,max(u,v));
        while(ss){
            ss >> u >> v;
            if(!u && !v) break;
            nodes = max(nodes,max(u,v));
            vv.pb(Edge(u,v));
        }
        Graph g(nodes,vv.size());
        //cout << "nodes " << nodes << " size " << vv.size() << endl;
        for(int i = 0 ; i < vv.size() ; i++){
            Edge e = vv[i];
            g.addEdge(e.from,e.to,1);
        }
        //g.printMatrix();
        g.FloydWarshall();
        printf("Case %d: average length between pages = %0.3f clicks\n",++kases,g.answer());
    }
    return 0;
}

