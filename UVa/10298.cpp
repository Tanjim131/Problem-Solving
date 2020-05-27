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

string input;
vector < int > ;

void precompute(int ret){
    vv.clear();
    for(int i = 1 ; i <= sqrt(ret) ; i++){
        if(ret % i == 0){
            int qq = ret / i;
            if(i != qq){
                vv.pb(i);
                vv.pb(qq);
            }
            else vv.pb(i);
        }
    }
    sort(vv.begin(),vv.end());
}

bool check(int val){
    int len = input.size();
    if(len % val) return false;
    int qq = len / val;
    string temp(input.begin(),input.begin() + qq);
    string res = "";
    while(val--) {res += temp;}
    if(res == input) return true;
    return false;
}

int ret(){
    for(int i = vv.size() - 1 ; i >= 0 ; i--){
        if(check(vv[i])) return vv[i];
    }
}

int main(){
    //infile;outfile;
    while(getline(cin,input)){
        if(input == ".") break;
        precompute(input.size());
        int ans = ret();
        printf("%d\n",ans);
    }
    return 0;
}


