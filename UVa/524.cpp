#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

int isPrime(int n){
    int sqrtN = std::sqrt(n);
    for(int i = 2 ; i <= sqrtN ; ++i){
        if(n % i == 0) return false;
    }
    return true;
}

std::vector<int> generate_prime_status(){
    std::vector <int> prime_status(33, 0);
    for(int i = 2 ; i <= 32 ; ++i){
        if(isPrime(i)) prime_status[i] = 1;
    }
    return prime_status;
}

void backtrack(std::vector<int> &numbers_placed, std::vector<int> &numbers_used, const std::vector<int> &prime_status, int index = 1, bool odd = false){
    if(index == numbers_placed.size()){
        int sum = numbers_placed[index - 1] + numbers_placed[0];
        if(prime_status[sum] == 1){
            for(int i = 0 ; i < numbers_placed.size() ; ++i){
                std::cout << numbers_placed[i];
                if(i != numbers_placed.size() - 1) std::cout << " ";
            }
            std::cout << '\n';
        }
        return;
    }
    int starting_number = 2;
    if(odd) starting_number = 3;
    for(int i = starting_number ; i <= numbers_placed.size() ; i += 2){
        if(!numbers_used[i]){
            int sum = i + numbers_placed[index - 1];
            if(prime_status[sum] == 1){
                numbers_used[i] = 1;
                numbers_placed[index] = i; // cannot print early, placement may not satisfy later
                backtrack(numbers_placed, numbers_used, prime_status, index + 1, odd ^ 1);
                numbers_used[i] = 0;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    std::vector <int> primes_status = generate_prime_status();
    int n, k = 0;
    while(std::cin >> n){
        std::vector <int> numbers_placed(n);
        std::vector <int> numbers_used(n + 1, 0);
        numbers_placed[0] = 1;
        if(k > 0) std::cout << '\n';
        std::cout << "Case " << ++k << ":\n";
        backtrack(numbers_placed, numbers_used, primes_status);
    }
    return 0;
}