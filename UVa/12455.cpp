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

int ara[25];
int n,p;

bool process(){
    for(int i = 0 ; i < (1 << p) ; i++){
        int sum = 0;
        for(int j = 0 ; j < p ; j++){
            if(i & (1 << j)) sum += ara[j];
        }
        if(sum == n) return true;
    }
    return false;
}

int main(){
    //infile; outfile;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&p);
        for(int i = 0 ; i < p ; i++) scanf("%d",&ara[i]);
        if(process()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


