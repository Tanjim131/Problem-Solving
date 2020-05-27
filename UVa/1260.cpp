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
#define PII pair < int , int >
#define infile(f) freopen(f,"r",stdin)
#define outfile(f) freopen(f,"w",stdout)

inline bool checkBit(int mask,int pos) { return (bool) (mask & (1 << pos)); }
inline int setBit(int mask,int pos) { return (mask | (1 << pos)); }
//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction


const int MAXN = 1000 + 5;
int arr[MAXN];

int solve(int n){
    int ret = 0;
    for(int i = 1 ; i < n ; i++){
        int counter = 0;
        for(int j = 0 ; j < i ; j++){
            if(arr[j] <= arr[i]) counter++;
        }
        ret += counter;
    }
    return ret;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&arr[i]);
        }
        printf("%d\n",solve(n));
    }
    return 0;
}
