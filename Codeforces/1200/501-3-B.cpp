#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    vector <int> moves; 
    moves.reserve(10000);
    bool possible = true;
    for(int i = 0 ; i < n; ++i){
        if(s[i] == t[i]) continue;
        // find t[i] in [i + 1, n)
        bool found = false;
        for(int j = i + 1 ; j < n ; ++j){
            if(s[j] == t[i]){
                for(int k = j - 1 ; k >= i ; --k){
                    swap(s[k], s[k + 1]);
                    moves.emplace_back(k + 1);
                }
                found = true;
                break;
            }
        }
        if(!found){
            possible = false;
            break;
        }
    }
    if(!possible || moves.size() > 10000){
        cout << "-1\n";
    } else{
        cout << moves.size() << '\n';
        for(auto move : moves){
            cout << move << " ";
        }
        cout << '\n';
    }
    return 0;
}
