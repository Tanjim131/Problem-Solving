#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[])
{
    long long H,L;
    std::cin >> H >> L;
    double depth = (L + H) * (L - H) / 2.0 / H;
    std::cout << std::fixed << std::setprecision(17) << depth << '\n';
    return 0;
}
