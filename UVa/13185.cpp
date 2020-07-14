#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

std::vector <int> get_proper_divisors(int n){
    std::vector <int> proper_divisors; proper_divisors.reserve(100); // size <= 2 * sqrt(n); n_max = 1000, size_max ~ 63
    proper_divisors.emplace_back(1);
    int sqrtN = static_cast<int>(std::sqrt(n));
    for(int i = 2 ; i <= sqrtN ; ++i){
        if(n % i == 0){
            proper_divisors.emplace_back(i);
            int other = n / i;
            if(other != i) proper_divisors.emplace_back(other);
        }
    }
    return proper_divisors;
}

int compute_status(int n){
    std::vector <int> proper_divisors = get_proper_divisors(n);
    int sum_of_proper_divisors = std::accumulate(proper_divisors.begin(), proper_divisors.end(), 0);
    if(sum_of_proper_divisors < n) return -1;
    if(sum_of_proper_divisors == n) return 0;
    return 1;
}

void printStatus(int n){
    int status = compute_status(n);
    if(status == -1){
        std::cout << "deficient\n";
    } else if(!status){
        std::cout << "perfect\n";
    } else{
        std::cout << "abundant\n";
    }
}

int main(int argc, char const *argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        int n;
        std::cin >> n;
        printStatus(n);
    }
    return 0;
}
