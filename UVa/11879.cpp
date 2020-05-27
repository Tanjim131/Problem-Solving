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

const int MAXN = 105;
char ara[MAXN];

bool check(){
    int len = strlen(ara);
    int rem = 0;
    for(int i = 0 ; i < len ; i++){
        rem = (rem * 10 + (ara[i] - '0')) % 17;
    }

    return rem == 0;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%s",ara) != EOF){
        if(strlen(ara) == 1 && ara[0] == '0') break;
        printf("%d\n",check());
    }
    return 0;
}

