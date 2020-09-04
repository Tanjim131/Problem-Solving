#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int diff = abs(a - b);
        int steps = diff / 10;
        if(diff % 10 != 0) ++steps;
        cout << steps << '\n';
    }
    return 0;
}
