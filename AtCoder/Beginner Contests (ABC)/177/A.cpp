#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int D, T, S;
    cin >> D >> T >> S;
    int t = static_cast<int>(ceil(D * 1.0 / S));
    cout << (T >= t ? "Yes": "No") << '\n';
    return 0;
}
