#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>

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

const int MAXN = 50000 + 5;
int ara_y[MAXN];

int main(){
    //infile; outfile;
    int T,kase = 0;
    scanf("%d",&T);
    while(T--){
        int N,width;
        scanf("%d %d",&N,&width);
        for(int i = 0 ; i < N ; i++){
            int x,y; scanf("%d %d",&x,&y);
            ara_y[i] = y;
        }

        sort(ara_y,ara_y + N);

        int ret = 0;
        int i = 0,j = 0;

        while(j < N){
            if(ara_y[j] - ara_y[i] > width){
                ret++;
                i = j;
            }
            j++;
        }

        ret++;

        printf("Case %d: %d\n",++kase,ret);
    }
    return 0;
}

