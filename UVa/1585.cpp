#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    string in;
    getchar();
    while(T--){
        cin >> in;
        int prev = 0 , tot = 0;
        for(int i = 0 ; i < in.size() ; i++){
            if(in[i] == 'X') prev = 0;
            else prev++;
            tot += prev;
        }
        printf("%d\n",tot);
    }
    return 0;
}

