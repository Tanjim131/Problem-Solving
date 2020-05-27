#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

char* add(char *a, char *b){
    char *sum = new char [250];

    int la = strlen(a);
    int lb = strlen(b);

    if(la <= lb){
        for(int i = la ; i > 0 ; i--){
            a[i] = a[i - 1];
            b[i] = b[i - 1];
            int aa = (a[i] - '0') + (b[i] - '0');
            cout << a[i] << " " << b[i] << " " << aa << endl;
            int ss = aa % 10;
            int carry = aa / 10;
            if(aa > 9){
                sum[i] = ss + '0';
                sum[i - 1] = carry + '0';
            }
        }
    }
    else{

    }
}

int main(){
    int T;
    //scanf("%d",&T);
    char aa[250],bb[250];
    while(T--){
        scanf("%s %s",aa,bb);
        char *res = add(aa,bb);
    }

    return 0;
}
