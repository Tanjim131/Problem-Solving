#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--){
        int r, g, b, w;
        cin >> r >> g >> b >> w;
        int odd_count = 0;
        if(r % 2) ++odd_count;
        if(g % 2) ++odd_count;
        if(b % 2) ++odd_count;
        if(w % 2) ++odd_count;
        if(odd_count < 2){
            cout << "Yes\n";
        } else if(odd_count == 2){
            cout << "No\n";
        } else if(r != 0 && g != 0 && b != 0){
            cout << "Yes\n";
        } else{
            cout << "No\n";
        }
    }
    return 0;
}
