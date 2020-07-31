#include <iostream>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--){
        int l,r;
        cin >> l >> r;
        int x = l, y = l * 2;
        if(y > r){
            cout << "-1 -1\n";
        } else{
            cout << x << " " << y << '\n';
        }
    }
    return 0;
}
