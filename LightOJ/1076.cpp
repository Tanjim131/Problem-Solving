#include<cstdio>
 
using namespace std;
 
#define MAXN 1005
 
bool check(int arr[],int n,int check_value,int container){
    int temp = check_value;
 
    for(int i = 0 ; i < n && container > 0; i++){
        if(arr[i] > check_value) return false;
 
        temp -= arr[i];
 
 
        if(temp < 0){
            container--;
            temp = check_value;
            temp -= arr[i];
        }
 
       //cout << "temp " << temp << " container " << container << endl;
    }
 
    if(container > 0) return true;
    return false;
}
 
long long binary(int arr[],int n,int container){
    long long low = 1, high = 1e9;
    long long mid = 0;
 
    while(low <= high){
        mid = (low + high)/2;
 
        //cout << "low " << low << " high " << high << " mid " << mid << endl;
 
        if(check(arr,n,mid,container)) high = mid - 1;
        else low = mid + 1;
 
        //cout << "low " << low << " high " << high << " mid " << mid << endl;
    }
 
    return low;
}
 
int main(){
    int T, k = 0; scanf("%d",&T);
 
    while(T--){
        int n,m; scanf("%d %d",&n,&m);
 
        int max_value = 0; int vessel[MAXN];
 
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&vessel[i]);
            max_value = max_value > vessel[i] ? max_value : vessel[i];
        }
 
        if(n >= m) printf("Case %d: %d\n",++k,binary(vessel,n,m));
        else printf("Case %d: %d\n",++k,max_value);
    }
 
    return 0;
}