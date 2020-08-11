#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector <int> v(n);
        for(int i = 0 ; i < n ; ++i) {
            cin >> v[i];
        }

        bool possible = true;
        int increasing = -1;
        for(int i = 0 ; i < n ; ++i){
            if(v[i] >= i){
                increasing = i;
            } else{
                break;
            }
        }
        int decreasing = n;
        for(int i = n - 1 ; i >= 0 ; --i){
            if(v[i] >= n - 1 - i){
                decreasing = i;
            } else{
                break;
            }
        }

        if(decreasing > increasing){
            possible = false;
        }

        if(possible){
            cout << "Yes\n";
        } else{
            cout << "No\n";
        }
    }
    return 0;
}
