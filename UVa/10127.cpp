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

int n;

int check(){
   int rem = 0;
   int digit = 0;
   while(1){
        rem = (rem * 10 + 1) % n;
        digit++;
        if(!rem) break;
   }

   return digit;
}

int main(){
    //infile; outfile;
    while(scanf("%d",&n) != EOF){
        printf("%d\n",check());
    }

    return 0;
}


