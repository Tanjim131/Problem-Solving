#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<sstream>

using namespace std;

bool condition(char i){
    if((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z')) return true;
    return false;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string input;
    while(getline(cin,input)){
        stringstream ss(input);
        string parse;
        int counter = 0;
        while(ss >> parse){
            bool flag = false;
            int len = parse.size();
            int i = 0;
            while(i < len){
                if(condition(parse[i])){
                    counter++;
                    while(condition(parse[i])) i++;
                }
                else i++;
            }
        }
        printf("%d\n",counter);
    }
    return 0;
}
