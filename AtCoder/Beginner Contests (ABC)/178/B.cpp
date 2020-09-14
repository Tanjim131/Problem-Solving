#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max({1LL * a * c, 1LL * b * d, 1LL * a * d, 1LL * b * c}) << '\n';
    return 0;
}
