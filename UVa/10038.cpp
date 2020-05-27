#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>

using namespace std;

int main()

{
    int n;
    while(scanf("%d",&n) != EOF)
    {

        int *ara = new int[n + 5];
        int *ara1 = new int[n + 5];

        for(int i = 0 ; i < n + 5 ; i++) ara1[i] = 0;


        for(int i=0;i<n;i++){
            scanf("%d",&ara[i]);
        }

        for(int i = 1 ; i < n ; i++){
            int diff = abs(ara[i] - ara[i - 1]);
            ara1[diff] = 1;
        }

        bool check = true;

        for(int i = 1 ; i <= n - 1 ; i++){
            if(ara1[i] == 0){
                check = false;
                break;
            }
        }

        if(check) printf("Jolly\n");

        else printf("Not jolly\n");
    }

    return 0;
}

