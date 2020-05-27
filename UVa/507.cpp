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

int ara[20005];

int n,a,b;

void ret(){
    int sum = 0 , ans = 0;
    int cur = 0 , prev = 0;
    int l = 0;
    for(int i = 1 ; i < n ; i++){
        sum += ara[i];
        if(ans < sum || (ans == sum && ((cur - prev == i - l && i < cur) || (cur - prev < i - l)))){
            ans = sum;
            prev = l;
            cur = i;
        }
        if(sum < 0){
            sum = 0;
            l = i;
        }
    }
    a = prev;
    b = cur;
}

int main(){
    //infile; outfile;
    int T,k = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        bool f = false;
        for(int i = 1 ; i < n ; i++){
            scanf("%d",&ara[i]);
            if(ara[i] > 0) f = true;
        }
        if(!f) printf("Route %d has no nice parts\n",++k);
        else {
            ret();
            printf("The nicest part of route %d is between stops %d and %d\n",++k,a + 1,b + 1);
        }
    }

    return 0;
}

