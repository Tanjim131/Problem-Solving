#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 10005;
int dp[MAXN][MAXN];

int LCS(string str1,string str2){
    int pp = str1.size() ;
    int qq = str2.size() ;

    if(pp == 0 || qq == 0) return 0;

    memset(dp,0,sizeof(dp));

    int i,j;
    for(i = 1 ; i < pp + 1 ; i++){
        for(j = 1 ; j < qq + 1 ; j++){
            if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
    }
    return dp[i - 1][j - 1];
}

int main(){
    string p,q;
    while(getline(cin,p) && getline(cin,q)){
        printf("%d\n",LCS(p,q));
    }
    return 0;
}
