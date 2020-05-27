#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int ara[205][105];
int partner[105] , freedom[105];
int n;

// checking if woman w prefers man m1 over man m
bool preference(int w , int m1 , int m){
    for(int i = 0 ; i < n ; i++){
        if( ara[w][i] == m1 ) return true;
        if( ara[w][i] == m ) return false;
    }
}

void stableMarriage(){
    memset(partner,-1,sizeof(partner));
    memset(freedom,0,sizeof(freedom));
    int counter = n;

    while(counter){
        int m;
        for(m = 0 ; m < n ; m++){
            if(!freedom[m]) break;
        }

        for(int i = 0 ; i < n && !freedom[m] ; i++){
            int w = ara[m][i];

            if(partner[w - n] == -1){
                partner[w - n] = m;
                freedom[m] = true ;
                counter--;
            }
            else{
                int m1 = partner[w - n];
                if(preference(w,m,m1)){
                    partner[w - n] = m;
                    freedom[m] = true;
                    freedom[m1] = false;
                }
            }
        }
    }
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,k = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i = 0 ; i < 2 * n ; i++){
            for(int j = 0 ; j < n ; j++){
                int x; scanf("%d",&x);
                x--; ara[i][j] = x;
            }
        }
        stableMarriage();
        printf("Case %d:",++k);
        for(int i = 0 ; i < n ; i++){
            printf(" (%d %d)",partner[i] + 1,i + n + 1);
        }
        printf("\n");
    }
    return 0;
}