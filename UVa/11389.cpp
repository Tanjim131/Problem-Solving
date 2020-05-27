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

int n,d,r;
int mor[105];
int eve[105];

int main(){
    //infile; outfile;
    while(scanf("%d %d %d",&n,&d,&r) != EOF){
        if(!n && !d && !r) break;
        int tot = 0;
        for(int i = 0 ; i < n ; i++) scanf("%d",&mor[i]);
        for(int i = 0 ; i < n ; i++) scanf("%d",&eve[i]);
        sort(mor,mor + n);
        sort(eve,eve + n);
        for(int i = 0 ; i < n ; i++){
            int qq = mor[i] + eve[n - i - 1] - d;
            tot += r * ( qq > 0 ? qq : 0); // pairwise morning + evening overpay reduce
        }
        printf("%d\n",tot);
    }

    return 0;
}


