#include<cstdio>
 
using namespace std;
 
int compute(int number,int digit){
    int res = 1; // initially there is only one digit
    int mod = digit % number;
    int i = digit;
 
    while(mod != 0){
        digit = (digit * 10) + i;
        digit = digit % number; // normal division
        mod = digit;
        res++;
    }
    return res;
}
 
int main(){
    int T,k = 0;
    scanf("%d",&T);
    while(T--){
        int number,digit;
        scanf("%d %d",&number,&digit);
        printf("Case %d: %d\n",++k,compute(number,digit));
    }
    return 0;
}