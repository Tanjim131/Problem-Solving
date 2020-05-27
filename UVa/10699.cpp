#include <iostream>
#include <vector>
#include <cmath>

inline int prime_factors(const std::vector <int> &primes, int n){
    int counter = 0;
    for(int i = 0 ; i < primes.size() && primes[i] <= n ; ++i){
        if(n % primes[i] == 0) {
            ++counter;
            while(n % primes[i] == 0) n /= primes[i];
        }
    }
    if(n > 1) ++counter;
    return counter;
}

std::vector <int> sieve(int N){
    std::vector <int> status(N + 1, 1);
    status[1] = 0;
    int sqrtN = sqrt(N);
    for(int i = 3 ; i <= sqrtN ; i += 2){
        if(status[i]){
            for(int j = i * i ; j <= N ; j += (i + i)){
                status[j] = 0;
            }
        }
    }

    std::vector <int> primes; 
    primes.reserve(3500);
    primes.emplace_back(2);
    
    for(int i = 1 ; i <= N ; i += 2){
        if(status[i]) primes.emplace_back(i);
    }
    return primes;
}

int main(int argc, char const *argv[])
{
    std::vector <int> primes = sieve(1000);
    int n;   
    while(std::cin >> n && n){
        std::cout << n << " : " << prime_factors(primes, n) << '\n';
    }
    return 0;
}
