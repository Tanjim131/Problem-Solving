#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--){
        string s,t,p;
        cin >> s >> t >> p;
        if(s.length() > t.length()){
            cout << "NO\n";
            continue;
        }
        int k = 0;
        vector <char> missing_count(26, 0);
        for(int i = 0 ; i < t.length() ; ++i){
            if(s[k] == t[i]) ++k;
            else ++missing_count[t[i] - 'a'];
        }
        if(k != s.length()){
            cout << "NO\n";
            continue;
        }
        vector <char> available_count(26, 0);
        for(int i = 0 ; i < p.length() ; ++i){
            ++available_count[p[i] - 'a'];
        }
        bool possible = true;
        for(int i = 0 ; i < 26 ; ++i){
            if(available_count[i] < missing_count[i]){
                possible = false;
                break;
            }
        }
        if(!possible){
            cout << "NO\n";
        } else{
            cout << "YES\n";
        }
    }
    return 0;
}
