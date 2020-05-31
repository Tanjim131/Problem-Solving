#include <iostream>
#include <cstdio>
#include <vector>
 
using namespace std;
 
const int MAXN = 100005;
vector < int > ara[MAXN];
double exp[MAXN];
 
void gen(){
    for(int i = 2 ; i <= MAXN ; i++){
        for(int j = i * 2 ; j <= MAXN ; j += i){
            ara[j].push_back(i);
        }
    }
}
 
void precalculate(){
    exp[1] = 0;
    for(int i = 2 ; i <= MAXN ; i++){
        int ret = ara[i].size() + 2;
        double ans = 2.0 / (ret * 1.0);
        for(int j = 0 ; j < ara[i].size() ; j++){
            ans += (1.0 / (ret * 1.0)) * (1 + exp[i / ara[i][j]]);
        }
        exp[i] = ans * ((ret * 1.0)/(ret - 1));
    }
}
 
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    gen();
    precalculate();
    int T,k = 0;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        printf("Case %d: %.10f\n",++k,exp[n]);
    }
    return 0;
}
 