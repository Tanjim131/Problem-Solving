#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

int number_of_divisors(long long n){
    int sqrtN = static_cast<int>(std::sqrt(n));
    int counter = 0;
    for(int i = 1 ; i <= sqrtN ; ++i){
        //std::lldiv_t result = std::lldiv(n, i); // with optimization turned on, this may be slower
        if(n % i == 0){
        //if(!result.rem){
            ++counter;
            int other = n / i;
            if(other != i) ++counter;
            //if(result.quot != i) ++counter;
        //}
        }
    }
    return counter;
}

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    long long g = -1;
    for(int i = 0 ; i < n ; ++i){
        long long x; std::cin >> x;
        if(g == -1) g = x;
        else g = std::__gcd(g, x);
    }
    std::cout << number_of_divisors(g) << '\n';
    return 0;
}
