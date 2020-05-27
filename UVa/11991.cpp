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

struct number{
    int num;
    int pos;
}ara[100005];

bool cmp(number a,number b){
    if(a.num == b.num) return a.pos < b.pos;
    return a.num < b.num;
}

int n,query;

int binary(int res,int kth){
    int low = 1 , high = n;
    int low_bound = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(ara[mid].num == res){
            low_bound = mid;
            high = mid - 1;
        }
        else if(ara[mid].num < res) low = mid + 1;
        else high = mid - 1;
    }
    if(low_bound == -1) return -1;
    // found lower bound
    low = 1 , high = n;
    int up_bound = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(ara[mid].num == res){
            up_bound = mid;
            low = mid + 1;
        }
        else if(ara[mid].num < res) low = mid + 1;
        else high = mid - 1;
    }
    //found upper bound
    int range = (up_bound - low_bound) + 1;
    if(kth > range) return -1;
    return low_bound + kth - 1;
}

int main(){
    //infile;outfile;
    while(scanf("%d %d",&n,&query) != EOF){
        map < int , int > m;
        int qq = 1;
        for(int i = 1 ; i <= n ; i++){
            int x; scanf("%d",&x);
            if(m.find(x) == m.end()){
                m[x] = qq++;
                //printf("Mapping %d with %d\n",x,qq - 1);
            }
            ara[i].num = m[x];
            ara[i].pos = i;
        }
        sort(ara + 1,ara + n + 1,cmp);
        for(int i = 0 ; i < query ; i++){
            int p,q; scanf("%d %d",&p,&q);
            int counter = binary(m[q],p);
            if(counter == -1) printf("0\n");
            else printf("%d\n",ara[counter].pos);
        }

    }
    return 0;
}


