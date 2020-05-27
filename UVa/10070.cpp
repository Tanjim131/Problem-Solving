#include <iostream>
#include <cstdio>

using namespace std;

#define LL long long

inline bool div(string a,int b){
    LL dd = 0;

    for(int i = 0 ; i < a.size() ; i++){
        dd = (dd * 10 + (a[i] - '0')) % b;
    }

    return !dd;
}

inline bool leap (string year){
    return (div(year,4) && (!div(year,100) || div(year,400)));
}

inline bool huluculu (string year){
    return div(year,15);
}

inline bool Bulukulu (string year){
    return leap(year) && div(year,55);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string n;
    bool flag = true;
    while(cin >> n){
        if(flag) flag = false;
        else printf("\n");
        if(!leap(n) && !huluculu(n) && !Bulukulu(n)) printf("This is an ordinary year.\n");
        if(leap(n)) printf("This is leap year.\n");
        if(huluculu(n)) printf("This is huluculu festival year.\n");
        if(Bulukulu(n)) printf("This is bulukulu festival year.\n");
    }
    return 0;
}
