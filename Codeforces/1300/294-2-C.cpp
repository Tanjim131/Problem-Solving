#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n >> m;
    int answer = min({n, m, (n + m) / 3});
    cout << answer << '\n';
    return 0;
}
