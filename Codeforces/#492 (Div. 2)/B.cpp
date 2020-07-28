#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>

using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    std::vector <int> v(n);
    int minimum = std::numeric_limits <int>::max();
    for(int i = 0 ; i < n ; ++i){
        cin >> v[i];
        int k = std::ceil((v[i] - i) * 1.0 / n);
        int required = i + n * k;
        minimum = std::min(minimum, required);
    }
    cout << (minimum % n) + 1 << '\n';
    return 0;
}
