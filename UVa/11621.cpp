#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define LL long long

vector < LL > vv;

LL p3(int i){
    LL ans = 1;
    while(i--) ans *= 3;
    return ans;
}

void precompute(){
    for(int i = 0 ; i < 32 ; i++){
        LL two = (1LL << i);
        for(int j = 0 ; j < 21 ; j++){
            LL three = p3(j);
            LL ret = two * three;
            vv.push_back(ret);
            //printf("2^ %d: %lld 3^ %d: %lld ans: %lld\n",i,two,j,three,ret);
        }
    }
}

LL binary(int check){
    int low = 0 , high = vv.size() - 1;
    int idx = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(vv[mid] >= check){
            idx = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return vv[idx];
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    precompute();
    sort(vv.begin(),vv.end());
    int m;
    while(scanf("%d",&m) != EOF){
        if(m == 0) break;
        printf("%lld\n",binary(m));
    }
    return 0;
}
