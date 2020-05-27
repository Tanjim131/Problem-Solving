#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int n;

    while(scanf("%d",&n) != EOF){
        if(n == 0) break;

        int xx,yy;
        scanf("%d %d",&xx,&yy);

        for(int i = 0 ; i < n ; i++){
            int rsxx,rsyy;
            scanf("%d %d",&rsxx,&rsyy);

            if(rsxx == xx || rsyy == yy) printf("divisa\n");
            else if(rsxx > xx && rsyy > yy) printf("NE\n");
            else if(rsxx < xx && rsyy > yy) printf("NO\n");
            else if(rsxx > xx && rsyy < yy) printf("SE\n");
            else if(rsxx < xx && rsyy < yy) printf("SO\n");
        }
    }

    return 0;
}
