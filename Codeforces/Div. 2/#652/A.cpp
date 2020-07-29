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
        if(n % 4 == 0){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
    return 0;
}
