#include<cstdio>
#include<vector>
#include<string>
#include<sstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define LL long long

vector <LL> ret;

string tostr(LL i){
    stringstream ss;
    ss << i;
    return ss.str();
}

LL add(string a,string b){
    LL aa = strtoll(a.c_str(),nullptr,10);
    LL bb = strtoll(b.c_str(),nullptr,10);

    LL cc = aa + bb;

    return cc;
}

bool isKaprekar(LL n){
    LL sq = (LL) n * n;

    string ssq = tostr(sq);
    string temp;

    int len = ssq.size();

    for(int i = len - 1 ; i > 0 ; i--){
        temp.push_back(ssq[i]);
        ssq.pop_back();
        reverse(temp.begin(),temp.end());

        LL aa = strtoll(ssq.c_str(),nullptr,10);
        LL bb = strtoll(temp.c_str(),nullptr,10);

        if(add(ssq,temp) == n){
            if(aa == 0 || bb == 0) return false;
            return true;
        }

        reverse(temp.begin(),temp.end());
    }

    return false;
}


void gen(){
    for( LL i = 2 ; i <= 40000 ; i++ ){
        if(isKaprekar(i)) ret.push_back(i);
    }
}

int main(){
    int T,k = 0;
    scanf("%d",&T);
    gen();
    while(T--){
        int a,b;
        vector <LL> output;
        scanf("%d %d",&a,&b);
        printf("case #%d\n",++k);
        for(auto val : ret){
            if(a <= val && b >= val){
                output.push_back(val);
            }
            else if(val > b) break;
        }
        if(output.size() == 0) printf("no kaprekar numbers\n\n");
        else{
            for(auto val: output){
                printf("%lld\n",val);
            }
            if(T != 0) printf("\n");
        }
    }
    return 0;
}
