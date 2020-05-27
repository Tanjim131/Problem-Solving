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

using namespace std;

#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair < int , int >

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

LL ara[20];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,k = 0;
    while(scanf("%d",&n) != EOF){
        for(int i = 0 ; i < n ; i++) scanf("%lld",&ara[i]);
        LL prod = 0;
        for(int i = 0 ; i < n ; i++){
            LL temp = ara[i]; prod = max(prod,temp);
            for(int j = i + 1 ; j < n ; j++){
                temp *= ara[j];
                prod = max(prod,temp);
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n",++k,prod);
    }
    return 0;
}

