#include <iostream>
#include <cmath>

int compute(int R, int N){
    double fraction = R * 1.0 / N;
    int ans = static_cast <int>(fraction) - 1;
    int f = static_cast <int>(std::floor(fraction));
    int c = static_cast <int>(std::ceil(fraction));
    if(f != c) ++ans;
    return ans > 26 ? -1 : ans;
}

int main(int argc, char const *argv[])
{
    int k = 0;
    int R,N;
    while(std::cin >> R >> N && R && N){
        int ans = compute(R,N);
        std::cout << "Case " << ++k << ": ";
        if(ans == -1){
            std::cout << "impossible\n";
        } else{
            std::cout << ans << '\n';
        }
    }
    return 0;
}
