#include<cstdio>
#include<cstring>

using namespace std;

int check(char i){
    if(i == 'A' ||  i == 'E' || i ==  'I' || i ==  'O' || i ==  'U' || i == 'H' || i == 'W' || i == 'Y') return 0;
    return 1;
}

int gen(char i){
    if(i == 'B' || i == 'F' || i == 'P' || i == 'V') return 1;
    else if(i == 'C' || i == 'G' || i == 'J' || i == 'K' || i == 'Q' || i == 'S' || i == 'X' || i == 'Z') return 2;
    else if(i == 'D' || i == 'T') return 3;
    else if(i == 'L') return 4;
    else if(i == 'M' || i == 'N') return 5;
    else if(i == 'R') return 6;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char input[30];

    while(scanf("%s",input) != EOF){
        int len = strlen(input);
        int prev = 0;

        for(int i = 0 ; i < len ; i++){
            if(!check(input[i]))  prev = -1;
            else{
                int call = gen(input[i]);
                if(call != prev){
                    prev = call;
                    printf("%d",call);
                }
            }
        }
        printf("\n");
    }

    return 0;
}
