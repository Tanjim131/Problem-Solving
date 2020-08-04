#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

bool isPossible(const std::vector <std::string> &v){
    for(int i = 0 ; i < v.size() ; ++i){
        for(int j = i + 1 ; j < v.size() ; ++j){
            if(v[j].find(v[i]) == std::string::npos){
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    std::vector <std::string> v(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> v[i];
    }
    std::sort(v.begin(), v.end(), [&](const std::string &s, const std::string &t){
        return s.length() < t.length();
    });
    if(isPossible(v)){
        cout << "YES\n";
        for(auto str : v){
            cout << str << '\n';
        }
    } else{
        cout << "NO\n";
    }
    return 0;
}
