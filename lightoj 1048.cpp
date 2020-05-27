#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1005;
int arr[MAXN];
int n,k;

bool check(int value){
    int counter = 0 , sum = 0;
    int i = 0;
    while(i < n + 1){
        if(arr[i] > value || counter > k) return false;
        if(sum > value){
            counter++;
            sum = 0;
            i--;
        }
        sum += arr[i];
        i++;
    }
    if(sum > value) counter++;
    return counter <= k;
}

int binary(){
    int low = 0 , high = 1e8;
    int idx = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(check(mid)){
            idx = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return idx;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,qq = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        for(int i = 0 ; i < n + 1 ; i++) scanf("%d",&arr[i]);
        int ans = binary();
        printf("Case %d: %d\n",++qq,ans);

        int i = 0 , j = 0 , tot = 0;
        for(; i < n + 1; i++) {
			tot += arr[i];
			if(tot > ans || k - j > n - i) {
				tot -= arr[i];
				printf("%d\n", tot);
				j++;
				tot = arr[i];
			}
		}
		printf("%d\n", tot);
    }
    return 0;
}
