#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

#define LL long long
#define pb push_back
#define mp make_pair
#define PII pair < int , int >
#define infile(f) freopen(f,"r",stdin)
#define outfile(f) freopen(f,"w",stdout)

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

const int MAXN = 100 + 5;
int arr[MAXN];
int pos[MAXN];

inline int ret(int n){
    int counter = 0;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] != i + 1){
            int temp = pos[i + 1];
            int val = arr[i]; // keeping track of the value being swapped
            swap(arr[i],arr[pos[i + 1]]);
            pos[val] = temp; // updating the position array
            counter++; // increasing the number of swapping
        }
    }
    return counter;
}

int main(){
    //infile("in.txt");
    //outfile("out.txt");
    int T,kase = 0;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&arr[i]);
            pos[arr[i]] = i; // keeping track of their original position
        }
        printf("Case %d: %d\n",++kase,ret(n));
    }
    return 0;
}

