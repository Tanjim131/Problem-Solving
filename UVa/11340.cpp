#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<map>

using namespace std;

int cost[300];
char input[10005];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        memset(cost,0,sizeof(cost));
        map <char,int> mp;
        int aa = 0;
        int k; scanf("%d",&k);
        string in;
        getchar();
        for(int i = 0 ; i < k ; i++){
            getline(cin,in);
            mp[in[0]] = aa++;
            int cc = 0;
            for(int i = 2 ; i < in.size() ; i++) cc = 10 * cc + (in[i]- '0');
            cost[aa - 1] = cc;
        }

        int m; scanf("%d",&m);
        int cc = 0;
        string input;
        getchar();
        for(int i = 0 ; i < m ; i++){
            getline(cin,input);
            for(int j = 0 ; j < input.size(); j++){
                if(mp.find(input[j]) != mp.end()) cc += cost[mp[input[j]]];
            }
        }
        int aaa = cc % 100 , bbb = cc / 100;
        printf("%d.%02d$\n",bbb,aaa);
    }


    return 0;
}
