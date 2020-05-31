#include<iostream>
#include<cstdio>
 
using namespace std;
 
int test_bit(int n,int m){
    int x= n & (1<<m);
 
    if(!x) return 0;
    else return 1;
}
 
int set_bit(int n,int m){
 
    int x= 1<<m;
 
    return (n|x);
}
 
int reset_bit(int n,int m){
 
    int x= ~(1<<m);
 
    return (n&x);
}
 
int invert(int n,int m) {
 
    int x= 1<<m;
 
    n^=x;
 
    return n;
}
 
int main(){
 
    int T,i=0;
    scanf("%d",&T);
 
    while(T--) {
 
        int n;
        scanf("%d",&n);
 
        int counter_0=0,counter_1=0;
 
        int j;
 
        for(j=0;;j++)
        {
            if(test_bit(n,j)==1 && test_bit(n,j+1)==0) break;
 
            if(test_bit(n,j)==0) counter_0++;
            if(test_bit(n,j)==1) counter_1++;
        }
 
        n=invert(n,j);
        n=invert(n,j+1);
 
        int k;
 
        if(counter_1!=0) for(k=0;k<counter_1;k++) n=set_bit(n,k);
 
        if(counter_0!=0) for(;k<j;k++) n=reset_bit(n,k);
 
        printf("Case %d: %d\n",++i,n);
    }
 
    return 0;
}