#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

inline double solve(int a,int b){
    int aa = max(a,b);
    int bb = min(a,b);

    return (bb * 1.0)/aa;
}

int main(){
    string a,b;
    while(getline(cin,a) && getline(cin,b)){
        if(a.size() == 0 && b.size() == 0) { printf("\n"); continue; }

        int xx = 0 , yy = 0;
        bool c1 = false, c2 = false;

        for(int i = 0 ; i < a.size() ; i++){
            a[i] = tolower(a[i]);
            if(a[i] >= 'a' && a[i] <= 'z') { xx += (a[i] - 'a' + 1); c1 = true; }
        }

        int pp = (xx % 9 == 0) ? 9 : xx % 9;

        for(int i = 0 ; i < b.size() ; i++){
            b[i] = tolower(b[i]);
            if(b[i] >= 'a' && b[i] <= 'z') { yy += (b[i] - 'a' + 1); c2 = true; }
        }

        if(!c1 && !c2) { printf("\n"); continue; }

        int qq = (yy % 9 == 0) ? 9: yy % 9;

        if(pp == 0 || qq == 0 || !c1 || !c2) printf("0.00 %\n");
        else printf("%0.2f %\n",solve(pp,qq) * 100);
    }

    return 0;
}
