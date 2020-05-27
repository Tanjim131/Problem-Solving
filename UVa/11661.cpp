#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>

using namespace std;

#define MAX 1e9 + 7

int main(){
    int L;
    while(scanf("%d",&L) != EOF){
        if(L == 0) break;

        char a[2000005];
        scanf("%s",a);
        int len = strlen(a);

        int counter = MAX;
        int r = MAX, d = MAX;

        for(int i = 0 ; i < len ; i++){
            if(a[i] == 'Z'){
                counter = 0;
                break;
            }

            else if(a[i] == 'R'){
                r = i;
                counter = min(counter,abs(r - d));
            }

            else if(a[i] == 'D'){
                d = i;
                counter = min(counter,abs(r - d));
            }

        }

        printf("%d\n",counter);
    }

    return 0;
}
