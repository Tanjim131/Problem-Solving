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

int n,k;

int ret(){
    int counter = n;
    while(k > 1 && n >= k){
        int rem = n % k;
        n /= k;
        counter += n;
        n += rem;
    }
    return counter;
}

int main(){
    //infile;outfile;
    while(scanf("%d %d",&n,&k) != EOF){
        int counter = ret();
        printf("%d\n",counter);
    }
    return 0;
}


