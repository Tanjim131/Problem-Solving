#include<cstdio>
#include<cstring>

using namespace std;

#define MAXN 100005

/*

The # part gives you a 0x in the output string.
The 0 and the x count against your "8" characters listed in the 08 part.
You need to ask for 10 characters if you want it to be the same.

int i = 7;

printf("%#010x\n", i);  // gives 0x00000007
printf("0x%08x\n", i);  // gives 0x00000007
printf("%#08x\n", i);   // gives 0x000007
Also changing the case of x, affects the casing of the outputted characters.

printf("%04x", 4779); // gives 12ab
printf("%04X", 4779); // gives 12AB

*/

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,k = 0;
    scanf("%d",&T);
    char a[MAXN];
    int dump[105];
    while(T--){
        memset(dump,0,sizeof(dump));
        scanf("%s",a);
        int len = strlen(a);
        int counter = 0;
        for(int i = 0 ; i < len ; i++){
            if(a[i] == '>'){
                if(counter == 99) counter = 0;
                else counter++;
            }
            else if(a[i] == '<'){
                if(counter == 0) counter = 99;
                else counter--;
            }
            else if(a[i] == '+'){
                if(dump[counter] == 255) dump[counter] = 0;
                else dump[counter]++;
            }
            else if(a[i] == '-'){
                if(dump[counter] == 0) dump[counter] = 255;
                else dump[counter]--;
            }
        }

        printf("Case %d: ",++k);
        for(int i = 0 ; i < 100 ; i++){
            printf("%02X",dump[i]); // Here x give output as lowercase 1f , X gives output as uppercase 1F
                                    // removing 0 pads the numbers with spaces , 2 specifies the width
            if(i != 99) printf(" ");
        }
        printf("\n");
    }


    return 0;
}
