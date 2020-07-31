#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;

std::vector <int> sieve(int n = 3000){
    std::vector <int> status(n + 1, 1);
    status[1] = 0;
    int sqrtN = std::sqrt(n);
    for(int i = 3 ; i <= sqrtN ; i += 2){
        if(status[i] == 1){
            for(int j = i * i ; j <= n ; j += i + i){
                status[j] = 0;
            }
        }
    }
    std::vector <int> primes;
    primes.reserve(150);
    primes.emplace_back(2);
    for(int i = 3 ; i <= n ; i += 2){
        if(status[i] == 1){
            primes.emplace_back(i);
        }
    }
    return primes;
}

bool isAlmostPrime(int n, const std::vector <int> &primes){
    int divisors = 0;
    for(int i = 0 ; primes[i] <= n ; ++i){
        if(n % primes[i] == 0){
            ++divisors;
        }
        if(divisors > 2) break;
    }
    return divisors == 2;
}

int compute(int n, const std::vector <int> &primes){
    int counter = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(isAlmostPrime(i, primes)){
            ++counter;
        }
    }
    return counter;
}

int main(int argc, char const *argv[])
{
    std::vector <int> primes = sieve();
    int n;
    cin >> n;
    cout << compute(n, primes) << '\n';
    return 0;
}
