#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int a,b,c;
    cin >> a >> b >> c;
    int possible = std::min({a, b / 2, c / 4});
    cout << possible * 7 << '\n';
    return 0;
}
