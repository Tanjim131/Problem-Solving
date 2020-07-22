#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    map <string,int> phonebook;
    while(n--){
        string name;
        int number;
        cin >> name >> number;
        phonebook[name] = number;
    }
    string query;
    while(cin >> query){
        auto it = phonebook.find(query);
        if(it != phonebook.end()){
            cout << it -> first << "=" << it -> second << '\n';
        } else{
            cout << "Not found\n";
        }
    }
    return 0;
}
