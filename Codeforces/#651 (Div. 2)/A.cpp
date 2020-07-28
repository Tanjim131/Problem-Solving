#include <iostream>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if(n % 2 == 0){
            cout << n / 2 << '\n';
        } else{
            cout << (n - 1) / 2 << '\n';
        }
    }
    return 0;
}
