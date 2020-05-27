#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int MAXN = 3700;
int party[MAXN];

void preprocess(){
    for(int i = 6 ; i < 3700 ; i += 7){
        party[i] =  -1;
        party[i + 1] = -1;
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        memset(party,0,sizeof(party));
        preprocess();
        int days;
        scanf("%d",&days);
        int p;
        scanf("%d",&p);
        int counter = 0;
        for(int i = 0 ; i < p ; i++){
            int hortal; scanf("%d",&hortal);
            for(int i = hortal ; i <= days ; i += hortal){
                if(party[i] == 0){
                    counter++;
                    party[i] = 1;
                }
            }
        }
        printf("%d\n",counter);
    }
    return 0;
}
