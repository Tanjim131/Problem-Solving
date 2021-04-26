#include <iostream>
#include <algorithm>

using namespace std;

int lcm(int a, int b){
    return (a * b) / __gcd(a, b);
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--){
        string s, t;
        cin >> s >> t;
        int a = s.length(), b = t.length();
        int l = lcm(a, b);
        string ss, tt;
        for(int i = 0 ; i < l / a ; ++i){
            ss += s;
        }
        for(int j = 0 ; j < l / b ; ++j){
            tt += t;
        }
        if(ss == tt){
            cout << ss << '\n';
        } else{
            cout << "-1\n";
        }
    }
    return 0;
}
