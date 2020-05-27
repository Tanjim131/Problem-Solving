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


vector < int > vv;
int a,b,p,q;
LL prod;

int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a % b);
}

void precompute(int ret){
    vv.clear();
    for(int i = 1 ; i <= sqrt(ret) ; i++){
        if(ret % i == 0){
            int qq = ret / i;
            if(i != qq){
                vv.pb(i);
                vv.pb(qq);
            }
            else vv.pb(i);
        }
    }
    sort(vv.begin(),vv.end());
}

void check(){
    for(int i = vv.size() - 1 ; i >= 0 ; i--){
        int one = vv[i];
        int another = prod / one;
        if(gcd(one,another) == a){
            p = min(one,another);
            q = max(one,another);
            break;
        }
    }
}

int main(){
    //infile;outfile;
    int T;
    scanf("%d",&T);
    while(T--){
        p = -1 , q = -1;
        scanf("%d %d",&a,&b);
        precompute(b);
        prod = (LL) a * b;
        check();
        if(p == -1 && q == -1) printf("-1\n");
        else printf("%d %d\n",p,q);
    }
    return 0;
}


