#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int T; std::cin >> T;
    while(T--){
        int n; std::cin >> n;
        int mx = 0, mn = 100;
        for(int i = 0 ; i < n ; ++i){
            int x; std::cin >> x;
            mx = std::max(mx, x);
            mn = std::min(mn, x);
        }
        std::cout << 2 * (mx - mn) << '\n';
    }
    return 0;
}
