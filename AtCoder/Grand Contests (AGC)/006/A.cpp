#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    string s, t;
    cin >> s >> t;
    int j = 0;
    for(int i = 0 ; i < s.length() ; ++i){
        if(s[i] == t[j]){
            ++j;
        }
    }
    cout << s.length() + t.length() - j << '\n';
    return 0;
}
