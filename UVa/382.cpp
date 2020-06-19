#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <iomanip>

std::vector<int> generate_divisors(int n){
    std::vector <int> divisors;
    divisors.reserve(500); // n_max = 60000, max_divisors = O(2 * sqrt(n)) ~ 500
    if(n > 1) divisors.emplace_back(1); // common proper divisor except n = 1

    int sqrtN = std::sqrt(n);
    for(int i = 2 ; i <= sqrtN ; ++i){
        std::div_t result = std::div(n,i);
        if(!result.rem){
            divisors.emplace_back(i);
            if(result.quot != i) divisors.emplace_back(result.quot);
        }
    }
    return divisors;
}

bool isPerfectNumber(int n, int sum){
    return n == sum;
}

bool isDeficient(int n, int sum){
    return sum < n;
}

void generate_output(const std::vector<int> &numbers){
    std::cout << "PERFECTION OUTPUT\n";
    for(int i = 0 ; i < numbers.size() ; ++i){
        std::vector <int> divisors = generate_divisors(numbers[i]);
        int sum = std::accumulate(divisors.begin(), divisors.end(), decltype(divisors)::value_type(0));
        std::cout << std::setw(5) << std::right << numbers[i];
        if(isPerfectNumber(numbers[i],sum)){
            std::cout << "  PERFECT\n";
        } else if(isDeficient(numbers[i],sum)){
            std::cout << "  DEFICIENT\n";
        } else{
            std::cout << "  ABUNDANT\n";
        }
    }
    std::cout << "END OF OUTPUT\n";
}

int main(int argc, char const *argv[])
{
    std::vector <int> numbers;
    numbers.reserve(100);
    
    int N;
    while(std::cin >> N && N){
        numbers.emplace_back(N);
    }

    generate_output(numbers);

    return 0;
}
