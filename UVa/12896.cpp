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

multimap < int , char > mmp;

int one[105];
int two[105];

void preprocess(){
    int qq = 0; char pp = 'a';
    mmp.insert(mp(qq,' '));
    qq++;
    mmp.insert(mp(qq,'.')); mmp.insert(mp(qq,',')); mmp.insert(mp(qq,'?')); mmp.insert(mp(qq,'"'));
    qq++;
    mmp.insert(mp(qq,pp++)); mmp.insert(mp(qq,pp++)); mmp.insert(mp(qq,pp++));
    qq++;
    mmp.insert(mp(qq,pp++)); mmp.insert(mp(qq,pp++)); mmp.insert(mp(qq,pp++));
    qq++;
    mmp.insert(mp(qq,pp++)); mmp.insert(mp(qq,pp++)); mmp.insert(mp(qq,pp++));
    qq++;
    mmp.insert(mp(qq,pp++)); mmp.insert(mp(qq,pp++)); mmp.insert(mp(qq,pp++));
    qq++;
    mmp.insert(mp(qq,pp++)); mmp.insert(mp(qq,pp++)); mmp.insert(mp(qq,pp++));
    qq++;
    mmp.insert(mp(qq,pp++)); mmp.insert(mp(qq,pp++)); mmp.insert(mp(qq,pp++)); mmp.insert(mp(qq,pp++));
    qq++;
    mmp.insert(mp(qq,pp++)); mmp.insert(mp(qq,pp++)); mmp.insert(mp(qq,pp++));
    qq++;
    mmp.insert(mp(qq,pp++)); mmp.insert(mp(qq,pp++)); mmp.insert(mp(qq,pp++)); mmp.insert(mp(qq,pp++));
}

int main(){
    //infile;outfile;
    preprocess();
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++) scanf("%d",&one[i]);
        for(int i = 0 ; i < n ; i++) scanf("%d",&two[i]);
        for(int i = 0 ; i < n ; i++){
            auto range = mmp.equal_range(one[i]);
            int j = 1; auto it = range.first;
            for(; j < two[i] ; it++,j++);
            printf("%c",it -> second);
        }
        printf("\n");
    }
    return 0;
}


