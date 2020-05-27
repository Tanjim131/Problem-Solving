#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100005;
int arr[MAXN];
int y,p;
int counter,first,last;

void binary(){
    counter = 0 , first = 0 , last = 0;
    for(int i = 0 ; i < p ; i++){
        int low = i , high = p - 1;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] - arr[low] <= y - 1){
                while(mid < p && (arr[mid] - arr[low] <= y - 1)){
                    int popes = mid - low + 1;
                    if(counter < popes){
                        counter = popes;
                        first = arr[low];
                        last = arr[mid];
                    }
                    mid++;
                }
                break;
            }
            else high = mid - 1;
        }
     }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&y) != EOF){
        scanf("%d",&p);
        for(int i = 0 ; i < p ; i++) scanf("%d",&arr[i]);
        binary();
        printf("%d %d %d\n",counter,first,last);
    }
    return 0;
}
