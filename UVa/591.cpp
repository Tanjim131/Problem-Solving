#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

const int MAXN = 55;
int brick[MAXN];

int main(){
    int n,k = 0;
    while(scanf("%d",&n) != EOF){
        if(n == 0) break;

        int sum = 0;
        for(int i =  0 ; i < n ; i++) scanf("%d",&brick[i]) , sum += brick[i];

        int avg = sum / n;

        int counter = 0;

        for(int i = 0 ; i < n ; i++){
            if(brick[i] > avg){
                counter += brick[i] - avg;
            }
        }
        printf("Set #%d\n",++k);
        printf("The minimum number of moves is %d.\n\n",counter);
    }
    return 0;
}
