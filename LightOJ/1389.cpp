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
#define PII pair < int , int >
#define infile(f) freopen(f,"r",stdin)
#define outfile(f) freopen(f,"w",stdout)

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

const int MAXN = 100 + 5;
char arr[MAXN];
int len;

int solve(){
    int counter = 0;

    for(int i = 0 ; i < len ; i++){
        if(arr[i] == '.'){
            if(i + 1 == len){
                counter++;
                break;
            }
            else{
                counter++;
                i += 2;
            }
        }
    }

    return counter;
}

int main(){
    int T,kase = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%d %s",&len,arr);
        printf("Case %d: %d\n",++kase,solve());
    }
    return 0;
}


