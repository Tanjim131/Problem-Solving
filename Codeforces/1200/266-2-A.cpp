#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int t = n / m;
    //we can either buy the remaining single tickets or some extra tickets (whichever cost less)
    int cost = min(t * b, t * m * a) + min(b, (n % m) * a);
    cout << cost << '\n';
    return 0;
}
