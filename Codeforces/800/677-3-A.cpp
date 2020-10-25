#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        int digits = static_cast<int>(log10(x)) + 1;
        int row = x % 10;
        int key_presses = 10 * (row - 1);
        key_presses += digits * (digits + 1) / 2;
        cout << key_presses << '\n'; 
    }
    return 0;
}
