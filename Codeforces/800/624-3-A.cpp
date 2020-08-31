#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(a == b){
            cout << "0\n";
        } else if(a < b){
            cout << (a % 2 == b % 2 ? 2 : 1) << '\n';
        } else{
            cout << (a % 2 == b % 2 ? 1 : 2) << '\n';
        }
    }
    return 0;
}
