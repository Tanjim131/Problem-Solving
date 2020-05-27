#include <cstdio>

using namespace std;

int main(){
    //clock_t begin = clock();
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(1){
        int n,ith;
        scanf("%d",&n);
        if(n == -1) break;
        else scanf("%d",&ith);
        int nodes = (1 << n) - 1;
        int i = 1;
        int pos = 0;
        while(1){
            if(ith & 1){
                ith >>= 1; ith++;
                i = (i << 1);
                if(i > nodes) break;
                else pos = i;
            }
            else{
                ith >>= 1;
                i = (i << 1) + 1;
                if(i > nodes) break;
                else pos = i;
            }
        }
        printf("%d\n",pos);
    }
    //clock_t end = clock();
    //double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    //cout << elapsed_secs << "\n";
    return 0;
}
