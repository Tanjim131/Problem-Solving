#include<cstdio>

using namespace std;

inline bool isSquare(int a,int b,int c,int d){
    if(a == b && a == c && a == d){
        if(b == c && b == d){
            if(c == d) return true;
            return false;
        }
        return false;
    }
    return false;
}

inline bool isRectangle(int a,int b,int c,int d){
    if(a == b && c == d) return true;
    if(a == c && b == d) return true;
    if(a == d && b == c) return true;
    return false;
}

inline bool isQuadrangle(int a,int b,int c,int d){
    if((a + b + c) <= d) return false;
    if((a + b + d) <= c) return false;
    if((a + c + d) <= b) return false;
    if((b + c + d) <= a) return false;
    return true;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(a == 0 || b == 0 || c == 0 || d == 0){
            printf("banana\n");
            continue;
        }
        if(isSquare(a,b,c,d)) printf("square\n");
        else{
            if(isRectangle(a,b,c,d)) printf("rectangle\n");
            else{o
                if(isQuadrangle(a,b,c,d)) printf("quadrangle\n");
                else printf("banana\n");
            }
        }
    }
    return 0;
}
