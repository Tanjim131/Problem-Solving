#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 10005;
int arr[MAXN];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,match;
    while(scanf("%d",&n) != EOF){
        for(int i = 0 ; i < n ; i++) scanf("%d",&arr[i]);
        scanf("%d",&match);
        sort(arr,arr + n);

        int p = 0 , q = n - 1;
        int x = 0 , y = 0;

        while(p < q){
            if(arr[p] + arr[q] == match) x = p , y = q , p++;
            else if(arr[p] + arr[q] > match) q--;
            else p++;
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n",arr[x],arr[y]);
    }
    return 0;
}
