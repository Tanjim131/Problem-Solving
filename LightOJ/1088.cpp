#include<cstdio>
#include<utility>
 
using namespace std;
 
#define MAXN 100005
 
pair<int,bool> binary(int a[],int n,int key){
    int low = 0 , high = n - 1;
    int mid = 0;
 
    while(low <= high){
        mid = (low + high)/2;
        //cout << "low " << low << " high " << high << " mid " << mid << endl;
        if(a[mid] == key) return make_pair(mid,true);
            //high = mid - 1;
 
        else if(a[mid] > key) high = mid - 1;
        else low = mid + 1;
 
        //cout << "low " << low << " high " << high << " mid " << mid << endl;
    }
    return make_pair(low,false);
}
 
int main(){
    int T,k = 0; scanf("%d",&T);
 
    while(T--){
        int n,m; scanf("%d %d",&n,&m); int a[MAXN];
 
        for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
 
        printf("Case %d:\n",++k);
 
        for(int i = 0 ; i < m ; i++){
            int x,y; scanf("%d %d",&x,&y);
 
            pair<int,bool> l = binary(a,n,x);
            pair<int,bool> r = binary(a,n,y);
 
            int result = r.first - l.first;
 
            if(r.second == true) result++;
 
            printf("%d\n",result);
        }
    }
 
    return 0;
}