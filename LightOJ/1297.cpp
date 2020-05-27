#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

inline double answer (double L, double W){
    double a = L + W;
    //std::cout << "L * L - 10 * L * W + W * W " << L * L - L * W + W * W << "\n";
    double b = sqrt(L * L - L * W + W * W);
    double x1 = (a + b) / 6;
    double x2 = (a - b) / 6;

    double answer1 = std::max(L - 2 * x1, 0.0) * std::max(W - 2 * x1 , 0.0) * std::max(x1, 0.0);
    double answer2 = std::max(L - 2 * x2, 0.0) * std::max(W - 2 * x2 , 0.0) * std::max(x2, 0.0);
    return std::max(answer1, answer2);
}

int main(int argc, char const *argv[])
{
    int T, k = 0; std::cin >> T;
    while(T--){
        double L,W;
        std::cin >> L >> W;
        double max_volume = answer(L, W);
        if(max_volume < 1e-6) max_volume = 0;
        std::cout << "Case " << ++k << ": " << std::setprecision(20) << max_volume << '\n';
    }
    return 0;
}
