#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair

vector < string > vv;

bool isValid(char a){
    return (a == '-') || (a >= 'a' && a <= 'z');
}

bool special (string a){
    bool f = true;
    for(int i = 0 ; i < a.size() ; i++){
        if(a[i] != '-'){
            f = false;
            break;
        }
    }
    return f;
}

void process(string a){
    if(a.size() && !special(a)){
        if(!vv.size() || a[0] == '-') vv.pb(a);
        else{
            string qq = vv.back();
            if(qq[qq.size() - 1] == '-'){
                qq.pop_back();
                string pp = qq + a;
                vv.pop_back();
                vv.pb(pp);
            }
            else vv.pb(a);
        }
    }
}

void clean (string a){
    string temp;
    for(int i = 0 ; i < a.size() ; i++){
        a[i] = tolower(a[i]);
        if(isValid(a[i])){
            temp += a[i];
        }
        else{
            process(temp);
            temp.clear();
        }
    }
    process(temp);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string input;
    bool f = false;
    while(getline(cin,input)){
        stringstream ss(input);
        while(ss >> input) clean(input);
    }
    sort(vv.begin(),vv.end());
    set < string > us;
    for(auto val : vv) us.insert(val);
    auto it = us.begin();
    while(it != us.end()){
        cout << *it << endl;
        it++;
    }
    return 0;
}
