#include <iostream>

using namespace std;

bool isEven(const string &s){
    int mid = s.length() / 2;
    for(int i = 0 ; i < mid ; ++i){
        if(s[i] != s[i + mid]) return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    s.pop_back(); s.pop_back();
    while(!isEven(s)){
        s.pop_back();
        s.pop_back();
    }
    cout << s.length() << '\n';
    return 0;
}
