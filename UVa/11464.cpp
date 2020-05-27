#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int arr[20][20];
int par[20][20];
int n;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void generate_parity(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < 4 ; k++){
                int pp = i + dx[k];
                int qq = j + dy[k];
                if(pp >= 0 && pp < n && qq >= 0 && qq < n){
                    if(arr[pp][qq] == 1) par[i][j]++;
                }
            }
        }
    }
}

int main(){
    int T,r = 0;
    scanf("%d",&T);
    while(T--){
        memset(par,0,sizeof(par));
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                scanf("%d",&arr[i][j]);
            }
        }
        generate_parity();

    }
    return 0;
}
