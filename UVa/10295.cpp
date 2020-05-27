#include <iostream>
#include <map>
#include <cstdio>
#include <sstream>

using namespace std;

#define LL long long

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int m,n;
    scanf("%d %d",&m,&n);
    map < string , int > mp;
    int cost;
    string input;
    for(int i = 0 ; i < m ; i++){
        cin >> input >> cost;
        if(mp.find(input) == mp.end()){
            mp[input] = cost;
        }
    }

    int counter = 0;
    LL cc = 0;
    getchar();
    while(getline(cin,input)){
        stringstream ss(input);
        string chk;
        ss >> chk;
        if(chk == "."){
            counter++;
            printf("%lld\n",cc);
            if(counter == n) break;
            cc = 0;
        }
        else{
            cc += mp[chk];
            while(ss >> chk){
                cc += mp[chk];
            }
        }
    }
    return 0;
}
