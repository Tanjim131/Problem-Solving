#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <cstdio>
#include <sstream>

using namespace std;

void trans()

int main(){
    string input;
    //getchar();
    while(getline(cin,input) && input != "****END_OF_INPUT****"){
        if(input == "****END_OF_TEXT****") continue;
        stringstream ss(input);
        while(ss >> input){

        }
        cout << endl;
    }
    return 0;
}
