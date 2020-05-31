#include <cstdio>
 
using namespace std;
 
const int MAXN = 100005;
int ara[MAXN];
int n;
 
bool check(int val){
    int diff = 0;
    for(int i = 0 ; i < n ; i++){
        diff = ara[i] - diff;
        if(diff > val || val < 0) return false;
        else if(diff == val) val--;
        diff = ara[i];
    }
    return true;
}
 
int binary(){
    int low = 0 , high = 1e8;
    int ans = -1;
 
    while(low <= high){
        int mid = (low + high)/2;
 
        if(check(mid)){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
 
    return ans;
}
 
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,k = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++) scanf("%d",&ara[i]);
        printf("Case %d: %d\n",++k,binary());
    }
    return 0;
}