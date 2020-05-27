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

int dp[35][35];
string a,b;

int call(int i,int j){
    if(i == a.size() || j == b.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if(a[i] == b[j]){
        ans = 1 + call(i + 1,j + 1);
    }
    else ans = max(call(i + 1,j),call(i,j + 1)) + 1;
    return dp[i][j] = ans;
}

int main(){
    cin >> a >> b;
    memset(dp,-1,sizeof(dp));
    int counter = call(0,0);
    cout << counter << endl;
    return 0;
}


