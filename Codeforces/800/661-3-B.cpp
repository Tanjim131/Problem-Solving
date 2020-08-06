#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using std::cin;
using std::cout;

int main(int, char const *[])
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        std::vector <int> a(n), b(n);
        int min_a = std::numeric_limits<int>::max();
        int min_b = std::numeric_limits<int>::max();
        for(int i = 0 ; i < n ; ++i) {
            cin >> a[i];
            min_a = std::min(min_a, a[i]);
        }
        for(int i = 0 ; i < n ; ++i) {
            cin >> b[i];
            min_b = std::min(min_b, b[i]);
        }
        long long moves = 0;
        for(int i = 0 ; i < n ; ++i){
            int required_a = a[i] - min_a;
            int required_b = b[i] - min_b;
            moves += std::max(required_a, required_b);
        }
        cout << moves << '\n';
    }
    return 0;
}
