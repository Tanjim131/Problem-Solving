#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2000005;
int arr[MAXN];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n) != EOF){
        if(n == 0) break;

        for(int i = 0 ; i < n ; i++){
            scanf("%d",&arr[i]);
        }

        sort(arr,arr + n);

        for(int i = 0 ; i < n ; i++) { printf("%d",arr[i]); if(i != n - 1) printf(" "); }
        printf("\n");
    }
    return 0;
}
