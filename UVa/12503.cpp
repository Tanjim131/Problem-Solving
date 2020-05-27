#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>

using namespace std;

const int MAXN = 105;
int arr[MAXN];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    string input;
    while(T--){
        memset(arr,0,sizeof(arr));
        int n;
        scanf("%d",&n);
        int p = 0;
        getchar();
        for(int i = 1 ; i <= n ; i++){
            getline(cin,input);
            stringstream ss(input);
            string temp;
            ss >> temp;
            if(temp == "LEFT") p-- , arr[i] = -1;
            else if(temp == "RIGHT") p++ , arr[i] = 1;
            else{
                string a;
                int c;
                ss >> a >> c;
                p += arr[c];
                arr[i] = arr[c];
            }
        }
        printf("%d\n",p);
    }
    return 0;
}
