#include <iostream>
#include <vector>
#include <cmath>


inline bool isPrime(const std::vector <int> &primes, int n){
    for(int i = 0 ; i < primes.size() && primes[i] <= n ; ++i){
        if(n != primes[i] && (n % primes[i] == 0)) return false;
    }
    return true;
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

    std::vector <int> primes; primes.reserve(3500);
    primes.emplace_back(2);
    for(int i = 1 ; i <= N ; i += 2){
        if(status[i]) primes.emplace_back(i);
    }
    return primes;
}

long long bigmod(int base, int exponent, int mod){
    if(exponent == 0) return 1;
    long long ret = bigmod(base, exponent >> 1, mod);
    ret = (ret * ret) % mod;
    if(exponent & 1) ret = (ret * base) % mod;
    return ret;
}

int main(int argc, char const *argv[])
{
    std::vector <int> primes = sieve(32000);
    int p, a;
    while(std::cin >> p >> a && p && a){
        int rem = bigmod(a, p, p);
        //std::cout << "a " << a << " p " << p << " rem " << rem << " isPrime " << isPrime(primes, p) << '\n';
        if(rem == a && !isPrime(primes, p)) std::cout << "yes\n";
        else std::cout << "no\n";
    }
    return 0;
}
