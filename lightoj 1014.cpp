#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define pb push_back

vector < int > vv;

void gen(int ret){
    vv.pb(1);
    for(int i = 2 ; i <= sqrt(ret) ; i++){
        if(ret % i == 0){
            int qq = ret / i;
            if(i != qq){
                vv.pb(i);
                vv.pb(qq);
            }
            else vv.pb(i);
        }
    }
    if(ret != 1) vv.pb(ret);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,k = 0;
    scanf("%d",&T);
    while(T--){
        vv.clear();
        int P,L;
        scanf("%d %d",&P,&L);
        int rem = (P - L);
        gen(rem);
        sort(vv.begin(),vv.end());
        vector < int > ans;
        for(int i = 0 ; i < vv.size() ; i++){
            if(vv[i] > L) ans.pb(vv[i]);
        }
        if(ans.size() == 0){
            printf("Case %d: impossible",++k);
        }
        else{
            printf("Case %d:",++k);
            for(int i = 0 ; i < ans.size() ; i++){
                printf(" %d",ans[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
