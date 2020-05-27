#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

struct d{
    int first;
    int second;
};

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2 ; i <= sqrt(n) ; i++){
        if(n % i == 0) return false;
    }
    return true;
}

d process(int n){
    d qq;
    qq.first = 0;
    qq.second = 0;
    for(int i = n ; i >= 2 ; i--){
        if(isPrime(i) && isPrime(n - i)){
            qq.first = n - i;
            qq.second = i;
            break;
        }
    }
    return qq;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n) != EOF){
        if(n == 0) break;
        d qq = process(n);
        printf("%d = %d + %d\n",n,qq.first,qq.second);
    }
    return 0;
}
