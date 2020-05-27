#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    string input;
    while(T--){
        getchar();
        set < string > s;
        multimap < string , int > mmp;
        int i = 1;
        while(getline(cin,input) != "END"){
            stringstream ss(input);
            while(ss >> input){
                //input.erase(remove_if(input.begin(),input.end(),[](char c){return !isalpha(c);}),input.end());
                //^^ removes all the non-alphanumeric letters from a string
                // remove_if returns an iterator to the element past that which return false for the unary predicate
                // then from that place to [first,end) erases all letters
                cout << input << endl;
            }
        }
    }
    return 0;
}
