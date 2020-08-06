#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

int main(int, char const *[])
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        std::vector <int> v(n);
        for(int i = 0 ; i < n ; ++i){
            cin >> v[i];
        }
        std::sort(v.begin(), v.end());
        bool possible = true;
        for(int i = 1 ; i < n ; ++i){
            if(v[i] - v[i - 1] > 1){
                possible = false;
                break;
            }
        }
        if(possible){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
    return 0;
}
