#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

int main(){
    string a;
    int counter = 0;
    while(getline(cin,a)){
        string b;
        for(int i = 0 ; i < a.size() ; i++){
            if(a[i] == '"'){
                if(counter & 1) { b.push_back(char(39));  b.push_back(char(39)); counter++;}
                else { b.push_back('`'); b.push_back('`'); counter++;}
            }
            else b.push_back(a[i]);
        }
        cout << b << endl;
    }

    return 0;
}
