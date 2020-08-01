#include <iostream>
#include <vector>

using std::cin;
using std::cout;

bool canConvert(unsigned char a, unsigned char b){
    if(a == 'O' && b == '0' || a == '0' && b == 'O') {
        return true;
    }
    if(a == '1'){
        if(b == 'L' || b == 'I') return true;
        return false;
    }
    if(a == 'L'){
        if(b == '1' || b == 'I') return true;
        return false;
    }
    if(a == 'I'){
        if(b == '1' || b == 'L') return true;
        return false;
    }
    return false;
}

bool isSimilar(const std::string &login, const std::string &existing){
    if(login.length() != existing.length()) return false;
    bool similar = true;
    for(int i = 0 ; i < login.length() ; ++i){
        unsigned char a = ::toupper(existing[i]);
        unsigned char b = ::toupper(login[i]);
        if(a == b) continue;
        if(!canConvert(a,b)){
            similar = false;
            break;
        }
    }
    return similar;
}

int main(int argc, char const *argv[])
{
    int n;
    std::string login;
    cin >> login >> n;
    std::vector <std::string> existing_logins(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> existing_logins[i];
    }
    bool similar = false;
    for(int i = 0 ; i < n ; ++i){
        if(isSimilar(existing_logins[i], login)){
            similar = true;
            break;
        }
    }
    if(similar){
        cout << "NO\n";
    } else{
        cout << "YES\n";
    }
    return 0;
}
