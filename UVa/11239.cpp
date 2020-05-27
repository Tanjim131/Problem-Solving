#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <sstream>
#include <string>
#inc

using namespace std;

int main(){
    string input;
    unordered_map < string , int > ump;
    vector < pair < string , set < string > > vv;
    string name;
    set < string > ss;
    while(getline(cin,input) && input != "0"){
        if(input == "1"){

        }
        else{
            if(input[0] >= 'A' && input[0] <= 'Z'){
                name = input;
            }
            else{
                ss.insert(input);
            }
        }
    }
    return 0;
}
