#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define LL long long

const int MAXN = 10005;

struct custom{
    int a;
    int b;
};

custom val[MAXN];

bool isOdd(int a){
    if(a < 0) a *= -1;
    return (a & 1);
}

bool isEven(int a){
    if(a < 0) a *= -1;
    return !(a & 1);
}

bool cmp(custom aa,custom bb){
    if(aa.b == bb.b){
        if(isOdd(aa.a) && isEven(bb.a)) return true;
        else if(isEven(aa.a) && isOdd(bb.a)) return false;
        else if(isOdd(aa.a) && isOdd(bb.a)) return aa.a > bb.a;
        else if(isEven(aa.a) && isEven(bb.a)) return aa.a < bb.a;
    }
    else return aa.b < bb.b;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    while(scanf("%d %d",&n,&m) != EOF){
        if(n == 0 && m == 0) {
            printf("0 0\n");
            break;
        }
        for(int i = 0 ; i < n ; i++) {
            int x; scanf("%d",&x);
            val[i].a = x;
            val[i].b = x % m;
        }
        sort(val,val + n,cmp);
        printf("%d %d\n",n,m);
        for(int i = 0 ; i < n ; i++){
            printf("%d\n",val[i].a);
        }
    }
    return 0;
}
