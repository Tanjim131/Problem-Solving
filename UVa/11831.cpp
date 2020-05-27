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

char ara[105][105];
char order[50005];
bool vis[105][105];
int n,m;

inline bool check(char i){
    return (i != '.') && (i != '*') && (i != '#');
}

inline bool isSafe(int x,int y){
    if(x >= 0 && x < n && y >= 0 && y < m && ara[x][y] != '#') return true;
    return false;
}

int main(){
    int s;
    while(scanf("%d %d %d",&n,&m,&s) != EOF){
        memset(vis,0,sizeof(vis));
        if(!n && !m && !s) break;
        char face; int sx,sy;
        for(int i = 0 ; i < n ; i++){
            scanf("%s",ara[i]);
            int len = strlen(ara[i]);
            for(int j = 0 ; j < len ; j++){
                if(check(ara[i][j])){
                    sx = i;
                    sy = j;
                    face = ara[i][j];
                }
            }
            //cout << ara[i] << endl;
        }
        //cout << face << " " << sx << " " << sy << endl;
        scanf("%s",order);
        //cout << order << endl;
        //cout << order << endl;
        int len = strlen(order);
        int counter = 0;
        for(int i = 0 ; i < len ; i++){
            if(order[i] == 'D'){
                if(face == 'N') face = 'L';
                else if(face == 'L') face = 'S';
                else if(face == 'S') face = 'O';
                else face = 'N';
            }
            else if(order[i] == 'E'){
                if(face == 'N') face = 'O';
                else if(face == 'L') face = 'N';
                else if(face == 'S') face = 'L';
                else face = 'S';
            }
            else{
                int px,py;
                if(face == 'N'){
                     px = sx - 1;
                     py = sy;
                }
                else if(face == 'L'){
                     px = sx;
                     py = sy + 1;
                }
                else if(face == 'S'){
                     px = sx + 1;
                     py = sy;
                }
                else{
                     px = sx;
                     py = sy - 1;
                }

                if(isSafe(px,py)){
                    sx = px;
                    sy = py;
                    if(ara[sx][sy] == '*' && !vis[sx][sy]){
                        vis[sx][sy] = true;
                        counter++;
                    }
                }
            }
            //cout << "sx " << sx << " sy " << sy << " face " << face << endl;
        }
        printf("%d\n",counter);
    }
    return 0;
}

