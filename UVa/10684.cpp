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

int ara[10005];

int main(){
    //infile; outfile;
    int n;
    while(scanf("%d",&n) != EOF){
        if(!n) break;
        for(int i = 0 ; i < n ; i++) scanf("%d",&ara[i]);
        int sum = 0 , ans = 0;
        for(int i = 0 ; i < n ; i++){
            sum += ara[i];
            ans = max(ans,sum);
            if(sum < 0) sum = 0;
        }
        if(ans <= 0) printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n",ans);
    }

    return 0;
}


