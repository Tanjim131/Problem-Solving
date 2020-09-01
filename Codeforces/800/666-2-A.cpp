#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> count(26, 0);
        for(int i = 0 ; i < n ; ++i){
            string s;
            cin >> s;
            for(int j = 0 ; j < s.length() ; ++j){
                ++count[s[j] - 'a'];
            }
        }
        // each alphabet count must be a multiple of n
        bool possible = true;
        for(int i = 0 ; i < 26 ; ++i){
            if(count[i] == 0) continue;
            if(count[i] % n != 0){
                possible = false;
                break;
            }
        }
        cout << (possible ? "YES" : "NO") << '\n';   
    }
    return 0;
}
