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

int ara[105];

int main(){
    string in;
    while(getline(cin,in)){
        stringstream ss(in);
        int n = 0; int qq;
        while(ss >> qq){
            if(qq == -999999) break;
            ara[n++] = qq;
        }
        int prod = 1 , ans = ara[0];
        for(int i = 1 ; i < n ; i++){
            prod *= ara[i];
            ans = max(ans,prod);
        }
        printf("%d\n",ans);
    }
    return 0;
}


