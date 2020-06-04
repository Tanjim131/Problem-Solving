#include <iostream>
#include <vector>
#include <cmath>

inline long long power(long long base, long long exponent){
    long long ans = 1;
    while(exponent--){
        ans *= base;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int C; 
    std::cin >> C;
    while(C--){
        int degree;
        std::cin >> degree;
        std::vector <int> coefficients(degree + 1);
        for(int i = 0 ; i < coefficients.size() ; ++i){
            std::cin >> coefficients[i];
        }
        int d,k;
        std::cin >> d >> k;
        int counter = 0;
        int n = std::ceil((-1 + std::sqrt(1 + (8.0 * k / d))) / 2.0);
        long long a_n = 0;
        for(int i = 0 ; i < coefficients.size() ; ++i){
            a_n += coefficients[i] * power(n, i);
        }
        std::cout << a_n << '\n';
    }
    return 0;
}
