#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 105;
char arr[MAXN][MAXN];
int x,y; // row , col

// direction array
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

void check(){
    for(int i = 0 ; i < x ; i++){
        for(int j = 0 ; j < y ; j++){
            if(arr[i][j] == '.'){
                int counter = 0;
                for(int k = 0 ; k < 8 ; k++){
                    int xx = i + dx[k];
                    int yy = j + dy[k];

                    if(xx >= 0 && xx < x && yy >= 0 && yy < y){
                        if(arr[xx][yy] == '*') counter++;
                    }
                }
                arr[i][j] = counter + '0';
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int k = 0;
    while(scanf("%d %d",&x,&y) != EOF){
        if(x == 0 && y == 0) break;
        if(k != 0) printf("\n");
        int sx = -1 , sy = -1;
        for(int i = 0 ; i < x ; i++){
            scanf("%s",arr[i]);
            int len = strlen(arr[i]);
        }
        check();
        printf("Field #%d:\n",++k);
        for(int i = 0 ; i < x ; i++){
            printf("%s\n",arr[i]);
        }
    }

    return 0;
}
