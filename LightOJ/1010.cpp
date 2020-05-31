#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,kase = 0;
    scanf("%d",&T);
    while(T--){
        int m,n;
        scanf("%d %d",&m,&n);
        if(m == 1 || n == 1) {
            printf("Case %d: %d\n",++kase,(m == 1) ? n : m);
            continue;
        }
        if(m == 2 || n == 2){
            int ret = (m == 2) ? n : m;

            if(ret & 1){
                int th = (ret >> 1) + 1;
                printf("Case %d: %d\n",++kase,th << 1);
            }
            else{
                int th = ret >> 1;
                if(th & 1) printf("Case %d: %d\n",++kase,ret + 2);
                else printf("Case %d: %d\n",++kase,ret);
            }

            continue;
        }
        int ret = (m * n) >> 1;
        if((m & 1) && (n & 1)) printf("Case %d: %d\n",++kase,ret + 1);
        else printf("Case %d: %d\n",++kase,ret);
    }
    return 0;
}
