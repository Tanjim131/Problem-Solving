#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    --n;
    int answer = 0;
    switch (n % 6)
    {
        case 0:
            answer = x;
            break;
        case 1:
            answer = y;
            break;
        case 2:
            answer = y - x;
            break;
        case 3:
            answer = -x;
            break;
        case 4:
            answer = -y;
            break;
        case 5:
            answer = x - y;
            break;
    }
    constexpr int MOD = 1000000007;
    answer = ((answer % MOD) + MOD) % MOD;
    cout << answer << '\n';
    return 0;
}
