#include<iostream>
#include<cstdio>

using namespace std;

#define LL long long
#define mp make_pair

pair<bool,LL> check(LL in){
    LL rev = 0;
    LL temp = in;
    while(in){
        rev = 10 * rev + in % 10;
        in /= 10;
    }
    if(rev == temp) return mp(true,rev);
    return mp(false,rev);
}

pair<LL,LL> ret(LL in){
    LL counter = 0;
    pair<bool,LL> ret;
    while(1){
        ret = check(in);
        if(ret.first == true && counter == 0){
            in <<= 1LL;
            counter++;
        }
        else if(ret.first == true && counter > 0) break;
        else {
            in = ret.second + in;
            counter++;
        }
    }
    return mp(counter,ret.second);
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        LL in;
        scanf("%lld",&in);
        pair<LL,LL> ans = ret(in);
        printf("%lld %lld\n",ans.first,ans.second);
    }
    return 0;
}
