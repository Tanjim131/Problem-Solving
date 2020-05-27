#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector < int > v;

int binary(int x){
    int low = 0;
    int high = v.size() - 1;
    int idx = -1;

    while(low <= high){
        int mid = (low + high)/2;

        if(v[mid] == x){
            idx = mid;
            high = mid - 1;
        }
        else if(v[mid] > x) high = mid - 1;
        else low = mid + 1;
    }

    return idx;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,q;
    int k = 0;
    while(scanf("%d %d",&n,&q) != EOF){
        if(n == 0 && q == 0) break;
        v.clear();
        for(int i = 0 ; i < n ; i++){
            int x; scanf("%d",&x);
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        printf("CASE# %d:\n",++k);
        for(int i = 0 ; i < q ; i++){
            int x; scanf("%d",&x);
            int qq = binary(x);
            if(qq == - 1) printf("%d not found\n",x);
            else printf("%d found at %d\n",x,qq + 1);
        }
    }
    return 0;
}
