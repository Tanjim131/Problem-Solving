#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
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
 
int ara[100005];
int n,k;
 
int ret(){
    deque < pii > dq;
    deque < pii > qd;
    int diff = 0;
    for(int i = 0 ; i < n ; i++){
        while(!dq.empty() && dq.back().first >= ara[i]) dq.pop_back();
        while(!qd.empty() && qd.back().first <= ara[i]) qd.pop_back();
        dq.pb(mp(ara[i],i));
        qd.pb(mp(ara[i],i));
        while(!dq.empty() && dq.front().second <= i - k) dq.pop_front();
        while(!qd.empty() && qd.front().second <= i - k) qd.pop_front();
        if(i >= k - 1){
            int mn = dq.front().first;
            int mx = qd.front().first;
            int qq = mx - mn;
            diff = max(diff,qq);
        }
    }
    return diff;
}
 
int main(){
    //infile; outfile;
    int T,r = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        for(int i = 0 ; i < n ; i++) scanf("%d",&ara[i]);
        printf("Case %d: %d\n",++r,ret());
    }
    return 0;
}
 