#include <iostream>
#include <string>
#include <map>
#include <cstdio>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);

    map < string , string > mp;
    string a,b;

    getchar();
    for(int i = 0 ; i < n ; i++){
        getline(cin,a);
        getline(cin,b);

        if(mp.find(a) == mp.end()) mp[a] = b;
    }

    int q; scanf("%d",&q);

    getchar();
    for(int i = 0 ; i < q ; i++){
        getline(cin,a);
        cout << mp[a] << endl;
    }

    return 0;
}
