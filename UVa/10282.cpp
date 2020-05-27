#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <sstream>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string input;
    map < string , string > mp;
    while(getline(cin,input) && input != ""){
        stringstream ss(input);
        string a,b;
        ss >> a >> b;
        if(mp.find(b) == mp.end()) mp[b] = a;
    }

    while(getline(cin,input)){
        if(mp.find(input) == mp.end()) printf("eh\n");
        else cout << mp[input] << "\n";
    }
    return 0;
}
