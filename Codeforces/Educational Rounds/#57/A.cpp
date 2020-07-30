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
        int x = l, y = 2 * l;
        cout << x << " " << y << '\n';
    }
    return 0;
}
