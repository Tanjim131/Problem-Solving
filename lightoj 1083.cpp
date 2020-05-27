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

using namespace std;

#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair < int , int >

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

const int MAXN = 30005;
LL ara[MAXN];
int n;

LL ret(){
    LL maxArea = 0;
    LL area = 0;
    int i;
    stack < int > ss;
    for(i = 0 ; i < n ;){
        if(ss.empty() || (ara[ss.top()] <= ara[i])){
            ss.push(i++);
        }
        else{
            int top = ss.top(); ss.pop();
            if(ss.empty()) area = ara[top] * i;
            else area = ara[top] * (i - ss.top() - 1);
            maxArea = max(maxArea,area);
        }
    }
    while(!ss.empty()){
        int top = ss.top(); ss.pop();
        if(ss.empty()) area = ara[top] * i;
        else area = ara[top] * (i - ss.top() - 1);
        maxArea = max(maxArea,area);
    }
    return maxArea;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,k = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++) scanf("%d",&ara[i]);
        printf("Case %d: %lld\n",++k,ret());
    }

    return 0;
}
